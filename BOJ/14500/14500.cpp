#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ans = 0;
int n, m;
vector<vector<int>> visited;

bool check(int r, int c){
    if(r < 0 || c < 0) return false;
    if(r >= n || c >= m) return false;
    return true;
}

void dfs(int r, int c, vector<vector<int>>& v, int depth, int sum){
    sum += v[r][c];
    visited[r][c] = 1;
    if(depth < 4){
        for(int i=0; i<4; ++i){
            if(!check(r+dy[i], c+dx[i])) continue;
            if(visited[r+dy[i]][c+dx[i]]) continue;

            r += dy[i];
            c += dx[i];
            dfs(r, c, v, depth+1, sum);
            r -= dy[i];
            c -= dx[i];
        }
    }
    
    ans = max(ans, sum);
    visited[r][c] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m, 0));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> v[i][j];
        }
    }

    visited.assign(n, vector<int>(m, 0));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            dfs(i, j, v, 1, 0);
        }
    }

    // ㅗ모양 별도 처리
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            int u=0, d=0, l=0, r=0;
            if(check(i+1, j) && check(i-1, j) && check(i, j-1))
                u = v[i][j] + v[i+1][j]             + v[i-1][j] + v[i][j-1];
            if(check(i+1, j) && check(i, j+1) && check(i-1, j))
                d = v[i][j] + v[i+1][j] + v[i][j+1] + v[i-1][j];
            if(check(i, j+1) && check(i-1, j) && check(i, j-1))
                l = v[i][j]             + v[i][j+1] + v[i-1][j] + v[i][j-1];
            if(check(i+1, j) && check(i, j+1) && check(i, j-1))
                r = v[i][j] + v[i+1][j] + v[i][j+1]             + v[i][j-1];

            ans = max(ans, u);
            ans = max(ans, d);
            ans = max(ans, l);
            ans = max(ans, r);
        }
    }
    
    cout << ans;
}