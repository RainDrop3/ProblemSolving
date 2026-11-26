#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(5, vector<int>(5, 0));
set<int> s;

int dr[4] = {0, -1, 0, 1};
int dc[4] = {1, 0, -1, 0};

bool check(int r, int c){
    if(r < 0 || c < 0) return false;
    if(r >= 5 || c >= 5) return false;
    return true;
}

void bt(int r, int c, int cnt, int num){
    if(cnt == 7) {
        s.insert(num);
        return;
    }
    for(int i=0; i<4; ++i){
        int nxt_r = r + dr[i], nxt_c = c + dc[i];
        if(!check(nxt_r, nxt_c)) continue;

        num = num*10 + v[nxt_r][nxt_c];
        cnt++;
        bt(nxt_r, nxt_c, cnt, num);
        cnt--;
        num = num/10;
    }
}

int main(){
    for(auto& row : v)
        for(int& i : row)
            cin >> i;

    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            bt(i, j, 1, 0);
        }
    }

    cout << s.size();
}