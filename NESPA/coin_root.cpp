// 내가 하다가 막힌 version
// 17 17, 16 18, 18 36 등의 edge case 해결 안됨

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, t_begin, t_end, time, N, idx = 0;
    vector<tuple<int, double>> stdin_data, pitcoin_data;
    vector<tuple<int, double, double>> block;

    //파일 입력
    ifstream input("Pitcoin.txt");
    double price, mini = numeric_limits<double>::max(), maxi = 0;
    input >> N;

    while (input >> time >> price) {
        pitcoin_data.emplace_back(time, price);
        if (price > maxi) maxi = price;
        if (price < mini) mini = price;
        if (++idx % 1414 == 1413) {
            block.emplace_back(time, mini, maxi);   //block 나누기
            maxi = 0;
            mini = numeric_limits<double>::max();
        }
    }
    if (idx%1414 != 0) block.emplace_back(time, mini, maxi);
    input.close();

    cin >> m;
    while (m--) {
        cin >> t_begin >> t_end;
        auto start_it = upper_bound(pitcoin_data.begin(), pitcoin_data.end(), make_tuple(t_begin, 0.0)) ;
        auto end_it = upper_bound(pitcoin_data.begin(), pitcoin_data.end(), make_tuple(t_end, 0.0)) ;

        int start_idx = int(start_it - pitcoin_data.begin())-1;
        int end_idx = int(end_it - pitcoin_data.begin())-1;

        int start_block_idx = start_idx / 1414;
        int end_block_idx = end_idx / 1414;

        auto start_block_it = (start_block_idx+1)*1414 + pitcoin_data.begin();
        auto end_block_it = end_block_idx*1414 + pitcoin_data.begin();

        //같은 블록 안에 있을 때
        cout << start_idx << " " << end_idx << endl;
        maxi = 0, mini = numeric_limits<double>::max();
        if (end_block_idx - start_block_idx <= 1) {
            for (int i=start_idx; i<=end_idx; i++) {
                if (get<1>(pitcoin_data[i]) > maxi) maxi = get<1>(pitcoin_data[i]);
                if (get<1>(pitcoin_data[i]) < mini) mini = get<1>(pitcoin_data[i]);
            }
        }
        else {
            //시작부분
            for (auto it = start_it; it < start_block_it; it++) {
                if (get<1>(*it) > maxi) maxi = get<1>(*it);
                if (get<1>(*it) < mini) mini = get<1>(*it);
            }

            //끝부분
            for (auto it = end_block_it; it <= end_it; it++) {
                if (get<1>(*it) > maxi) maxi = get<1>(*it);
                if (get<1>(*it) < mini) mini = get<1>(*it);
            }

            //중간부분
            for (int j = start_block_idx+1; j < end_block_idx; j++) {
                if (get<2>(block[j]) > maxi) maxi = get<2>(block[j]);
                if (get<1>(block[j]) < mini) mini = get<1>(block[j]);
            }
        }
        cout.precision(3);
        cout << fixed << mini << " " << maxi << endl;
    }
}