#include<iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<char>> v;
vector<vector<int>> dist;
int N, M;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    while (!q.empty()) {
        int cur_x = q.front().first, cur_y = q.front().second;

        q.pop();
        for (int i=0; i<4; ++i) {
            int new_x = cur_x + dx[i], new_y = cur_y + dy[i];
            if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M)
                continue;
            if (v[new_x][new_y] == '0')
                continue;

            v[new_x][new_y] = '0';
            dist[new_x][new_y] = dist[cur_x][cur_y] + 1;
            q.emplace(new_x, new_y);
        }
    }
}

int main() {
    cin >> N >> M;

    string s;
    v.resize(N);
    dist.resize(N);
    for (int i=0; i<N; ++i) {
        cin >> s;
        for (char& c : s)
            v[i].push_back(c);
        dist[i].assign(M, 1);
    }

    bfs(0, 0);
    cout << dist[N-1][M-1];
}
