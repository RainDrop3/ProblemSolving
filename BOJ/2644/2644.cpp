#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p1, p2, m;
    cin >> n >> p1 >> p2 >> m;

    vector<int> adj[101];
    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n+1, -1);
    queue<int> q;

    q.push(p1);
    dist[p1] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(curr == p2) break;

        for(int next : adj[curr]){
            if(dist[next] == -1){
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    cout << dist[p2];
}