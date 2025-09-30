#include <iostream>
#include <vector>
using namespace std;
//시작 위치는 점수X
//종료조건 : 음수를 만나면 종료하고 그 전까지의 합 출력
//
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, size, tmp, sum = 0;
    vector<int> board;

    cin >> T;
    while (T--) {
        cin >> size;
        board.resize(size);
        for (int i=0; i<size; ++i) {
            cin >> tmp;
            board[i] = tmp;
        }

        for (int i=0; i<size; ++i) {
            sum = 0;
            for (int j=i; j<size; ++j) {
                if (j == size-1) {
                    cout << 0 << " ";
                    break;
                }
                else if (board[j+1] >= 0) {
                    sum += board[j+1];
                }
                else {
                    cout << sum << " ";
                    break;
                }
            }
        }
        cout << endl;
    }
}