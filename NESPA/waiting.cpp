#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, k, num;
    char flag;
    cin >> N >> k;
    vector<vector<int>> room;

    for (int i=0; i<N; i++) {
        cin >> flag >> num;

        if (flag == '+') {
            int idx = -2;
            //최초 지원자 입장
            if (room.empty()) {
                room.push_back({num});
                idx = 0;
            }
            //지원자 입장
            else {
                //앉을 의자 정하기
                for (int j=0; j<room.size(); j++) {
                    if (num <= room[j][0]) {
                        idx = j-1;
                        break;
                    }
                }
                if (idx == -1) idx = 0;             //예외1) 앉을 의자가 첫번째 의자일때
                if (idx == -2) idx = room.size()-1; //예외2) 앉을 의자가 마지막 의자일때

                //의자에 앉기
                auto it = lower_bound(room[idx].begin(), room[idx].end(), num);
                room[idx].insert(it, num);
            }
            //의자가 다 차면 split
            if (room[idx].size() == 2*k) {
                vector<int> tmp;
                tmp.assign(room[idx].begin()+k, room[idx].end());
                room[idx].resize(k);
                room.insert(room.begin()+idx+1, tmp);
            }
        }
        // flag == '-'
        else {
            if (room.empty()) continue;

            auto it = lower_bound(room.begin(), room.end(), num,         //num이 있을 의자 찾기
                [](const vector<int>& v, int val) {return v.back() < val; });

            // 의자를 찾았다면
            if (it != room.end()) {
                auto it2 = lower_bound(it->begin(), it->end(), num);     //num이 있을 자리 찾기

                if (it2 != it->end() && *it2 == num) {
                    it->erase(it2);
                    if (it->empty()) room.erase(it);                     //의자가 비었으면 의자 삭제
                }
            }
        }
    }
    //출력
    for (int i=0; i<room.size(); i++) cout << room[i][0] << '\n';
}