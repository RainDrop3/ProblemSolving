// 윤성이가 준 version
// 제곱근 분할법 최종 성공
// 10.724 | 2976 | 575

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

struct DataPoint {
    int time;
    double price;
    bool operator<(const DataPoint& other) const {
        return time < other.time;
    }
};

struct BlockSummary {
    int end_time;
    double min_price;
    double max_price;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream pitcoin_file("Pitcoin.txt");
    int N, m, time, idx = 0, BLOCK_SIZE = 1414;
    double price, mini = numeric_limits<double>::max(), maxi = 0;
    pitcoin_file >> N;

    vector<DataPoint> pitcoin_data;
    vector<BlockSummary> block;

    pitcoin_data.reserve(N);

    while (pitcoin_file >> time >> price) {
        pitcoin_data.emplace_back(DataPoint{time, price});
        if (price > maxi) maxi = price;
        if (price < mini) mini = price;
        if (idx++ % BLOCK_SIZE == BLOCK_SIZE - 1) {
            block.emplace_back(BlockSummary{time, mini, maxi});
            maxi = 0;
            mini = numeric_limits<double>::max();
        }
    }
    if (idx % BLOCK_SIZE != 0) block.emplace_back(BlockSummary{time, mini, maxi});

    pitcoin_file.close();

    cin >> m;
    while (m--) {
        int t_begin, t_end;
        cin >> t_begin >> t_end;

        auto start_it = upper_bound(pitcoin_data.begin(), pitcoin_data.end(), DataPoint{t_begin, 0.0}) - 1;
        auto end_it = upper_bound(pitcoin_data.begin(), pitcoin_data.end(), DataPoint{t_end, 0.0}) - 1;

        maxi = -1.0;
        mini = numeric_limits<double>::max();

        int start_idx = start_it - pitcoin_data.begin();
        int end_idx = end_it - pitcoin_data.begin();

        //start_block, end_block은 각 block의 시작점을 가리킴.
        int start_block = start_idx / BLOCK_SIZE;
        int end_block = end_idx / BLOCK_SIZE;

        if (start_block == end_block) {
            for (auto it = start_it; it <= end_it; ++it) {
                if (it->price > maxi) maxi = it->price;
                if (it->price < mini) mini = it->price;
            }
        } else {
            for (int i = start_idx; i < (start_block + 1) * BLOCK_SIZE && i < pitcoin_data.size(); ++i) { //i < pitcoin_data.size() 도 필수?
                if (pitcoin_data[i].price > maxi) maxi = pitcoin_data[i].price;
                if (pitcoin_data[i].price < mini) mini = pitcoin_data[i].price;
            }
            for (int i = start_block + 1; i < end_block; ++i) {
                if (block[i].max_price > maxi) maxi = block[i].max_price;
                if (block[i].min_price < mini) mini = block[i].min_price;
            }
            for (int i = end_block * BLOCK_SIZE; i <= end_idx; ++i) {
                if (pitcoin_data[i].price > maxi) maxi = pitcoin_data[i].price;
                if (pitcoin_data[i].price < mini) mini = pitcoin_data[i].price;
            }
        }

        cout << fixed << setprecision(3) << mini << " " << maxi << endl;
    }
}