/*
 *vector<stack<int>>로 야적장<적치장> 할당.
 *stack.size()가 큰 거 찾아서 pop() -> size()가장 작은 곳에 다시 push()
 *maxi-mini <= 1 일때까지 반복
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, cnt_container, container, max_height, min_height, max_idx, min_idx;
    vector<vector<int>> yard; //야적장

    //입력
    cin >> N;
    yard.resize(N);
    for (int i=0; i<N; ++i) {
        cin >> cnt_container;
        yard[i].reserve(cnt_container+1);
        yard[i].push_back(-1);
        while (cnt_container--) {
            cin >> container;
            yard[i].push_back(container);
        }
    }

    //야적장 정리
    while (true) {
        max_height = 0;
        min_height = 10000;
        for (int i=0; i<N; ++i) {
            //최고 높이의 적치장 찾기
            if (yard[i].size() > max_height) {
                max_height = yard[i].size();
                max_idx = i;
            }
            //최고 높이가 같으면 무게로 비교
            else if (yard[i].size() == max_height) {
                if (yard[max_idx].back() < yard[i].back()) max_idx = i;
            }
            //최저 높이의 적치장 찾기
            if (yard[i].size() < min_height) {
                min_height = yard[i].size();
                min_idx = i;
            }
        }
         if (max_height - min_height <= 1) break;

        //컨테이너 옮기기
         container = yard[max_idx].back();
         yard[max_idx].pop_back();
         yard[min_idx].push_back(container);

    }

    //출력
    for (int i=0; i<N; ++i) {
        for (int j=1; j<yard[i].size(); ++j) {
            cout << yard[i][j] << " ";
        }
        if (yard[i].size() == 1) cout << 0;
        cout << '\n';
    }
}