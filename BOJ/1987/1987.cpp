#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v;
string s(26, 0);
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int n, m, maxi = 0;

bool check(int x, int y){
    if(x < 0 || y < 0) return false;
    if(x >= n || y >= m) return false;
    return true;
}

void bt(int r, int c, int cnt){
    for(int i=0; i<4; ++i){
        int nxt_r = r + dr[i], nxt_c = c + dc[i];
        if(!check(nxt_r, nxt_c)) continue;

        int idx = v[nxt_r][nxt_c] - 'A';
        if(s[idx]) continue;

        cnt++;
        s[idx] = 1;
        bt(nxt_r, nxt_c, cnt);
        s[idx] = 0;
        cnt--;
    }
    maxi = max(maxi, cnt);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    v.assign(n, vector<char>(m, '0'));
    for(auto& row : v){
        for(char& ch : row){
            cin >> ch;
        }
    }

    int idx = v[0][0] - 'A';
    s[idx] = 1;
    //cout << s;
    bt(0, 0, 1);

    cout << maxi;
}