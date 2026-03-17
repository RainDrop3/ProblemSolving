#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> board(9, vector<int>(9, 0));
vector<pair<int, int>> empties;

bool canPlace(int idx, int num){
    for(int i=0; i<9; ++i){
        //col검사
        if(board[i][empties[idx].second] == num)
            return false;
        //row검사
        if(board[empties[idx].first][i] == num)
            return false;
    }
    //box검사
    int r = empties[idx].first, c = empties[idx].second;
    while(r%3 != 0)
        r--;
    while(c%3 != 0)
        c--;
    for(int j=r; j<r+3; ++j){
        for(int k=c; k<c+3; ++k){
            if(board[j][k] == num)
                return false;
        }
    }
    return true;
}

bool solve(int idx){
    
    if(idx == (int)empties.size())
        return true;
    
    int r = empties[idx].first, c = empties[idx].second;
    for(int i=1; i<10; ++i){
        if(canPlace(idx, i)){
            int tmp = board[r][c];

            //backtracking
            board[r][c] = i;
            if(solve(idx+1))
                return true; //정답 찾았을 때
            board[r][c] = tmp; 
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //입력
    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            int num;
            cin >> num;
            board[i][j] = num;

            if(num == 0)
                empties.emplace_back(i, j);
        }
    }

    //backtracking
    solve(0);

    //출력
    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}