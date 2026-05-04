#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9
vector<int> adj[200001];
vector<int> visited, dist;
queue<pair<int, int>> q;

void bfs(int start, int dest){
    q.emplace(start, 0);
    visited[start] = 1;
    while (!q.empty()){
        auto[curr, iter] = q.front();
        q.pop();

        if (iter >= 3)
            break;

        for (int& next : adj[curr]){
            if (!visited[next]){
                visited[next] = 1;
                q.emplace(next, iter+1);
                dist[next] = iter+1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i=0; i<m; ++i){
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }

    visited.assign(n+1, 0);
    dist.assign(n+1, INF);

    bfs(1, n);
    if (dist[n] <= 2)
        cout << "POSSIBLE";
    else
        cout << "IMPOSSIBLE";
}