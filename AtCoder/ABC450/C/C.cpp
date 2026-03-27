#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> v;
queue<pair<int, int>> q;
int h, w, ans = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int r, int c){
    bool isDot = false;
    if (v[r][c] == '.'){
        q.emplace(r, c);
        v[r][c] = '#';
        isDot = true;
    }

    bool isBorder = false;
    while(!q.empty()){
        int qff = q.front().first, qfs = q.front().second;
        
        for(int i=0; i<4; ++i){
            if(qff+dx[i] < 0 || qff+dx[i] > h-1 || qfs+dy[i] < 0 || qfs+dy[i] > w-1){
                isBorder = true;
                continue;
            }
            if(v[qff+dx[i]][qfs+dy[i]] == '.'){
                q.emplace(qff+dx[i], qfs+dy[i]);
                v[qff+dx[i]][qfs+dy[i]] = '#';
            }
        }
        q.pop();
    }
    if(!isBorder && isDot)
        ans++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> h >> w;
    v.assign(h, vector<char>(w, 0));
    
    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
            cin >> v[i][j];
        }
    }

    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
            bfs(i, j);
        }
    }
    cout << ans;
}