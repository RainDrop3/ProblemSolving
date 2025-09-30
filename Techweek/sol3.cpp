#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, Q, tmp1, tmp2 = 0;
    long long sum = 0, idx = 0;
    vector<long long> chicken;
    vector<pair<int, int>> order;

    cin >> T;
    while (T--) {
        //cout << "----------------------------" << endl;
        cin >> Q;
        order.resize(Q);
        for (int i=0; i<Q; ++i) {
            order[i] = {0, 0};
        }
        sum = 0;
        for (int i=0; i<Q; ++i) {
            cin >> tmp1;
            if (tmp1 == 2) {
                cin >> tmp2;
                sum += tmp2;
            }
            order[i] = {tmp1, tmp2};
        }

        //cout << "sum: " << sum << endl;
        chicken.resize(sum);
        for (int i=0; i<sum; ++i) {
            chicken[i] = 0;
            //cout << chicken[i] << " ";
        }
        for (int i=0; i<Q; ++i) {
            //fry chickens
            //cout << endl;
            if (order[i].first == 2) {
                for (int j=0; j<order[i].second; ++j) {
                    auto it = find(chicken.begin(), chicken.end(), 0);
                    *it = 1;
                    idx = it - chicken.begin();
                    //cout << "j: " << j << " idx: " << idx << " begin: " << *chicken.begin() << endl;
                }
                cout << (idx+1)*2 << '\n';
            }
            else { //pick up a chicken
                auto it = find(chicken.begin(), chicken.end(), 1);
                *it = 0;
                idx = it - chicken.begin();

                cout << (idx+1)*2 << '\n';
            }
        }
    }
}

/*
3
10
2 3
2 4
1
1
1
1
1
1
2 1
1
10
2 3
2 4
1
1
1
1
1
1
2 1
1
10
2 3
2 4
1
1
1
1
1
1
2 1
1
 */