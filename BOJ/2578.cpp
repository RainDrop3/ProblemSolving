#include <iostream>
#include <vector>
using namespace std;

int CountBingo(int board[5][5]) {
    bool IsBingo = true;
    int bingo = 0;
    //가로 빙고
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (board[i][j] == 0) IsBingo = false;
        }
        if (IsBingo) bingo++;
        IsBingo = true;
    }

    //세로 빙고
    IsBingo = true;
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (board[j][i] == 0) IsBingo = false;
        }
        if (IsBingo) bingo++;
        IsBingo = true;
    }

    //대각선 빙고
    IsBingo = true;
    for (int i=0; i<5; i++) {
        if (board[i][i] == 0) IsBingo = false;
    }
    if (IsBingo) bingo++;

    IsBingo = true;
    for (int i=4, j=0; i>=0; i--, j++) {
        if (board[i][j] == 0) IsBingo = false;
    }
    if (IsBingo) bingo++;

    return bingo;
}

int main() {
    int tmp;
    int numbers[5][5];
    int board[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
    };
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin >> numbers[i][j];
        }
    }

    vector<int> bingo_number;
    for (int i=0; i<25; i++) {
        cin >> tmp;
        bingo_number.push_back(tmp);
    }

    int bingo = 0, cnt = 0;
    while (bingo < 3) {
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (bingo_number.front() == numbers[i][j]) {
                    board[i][j] = 1;
                    cnt++;
                    break;
                }
            }
        }
        bingo_number.erase(bingo_number.begin());
        bingo = CountBingo(board);
    }

    cout << cnt;


}