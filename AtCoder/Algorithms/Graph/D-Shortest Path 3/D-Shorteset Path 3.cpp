#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1e15

vector<ll> node_wei;
vector<pll> adj[200001]; // {cost, node}
vector<ll> dist;

void dijk(int start, int n){
    dist.assign(n+1, INF);
    priority_queue<pll, vector<pll>, greater<>> pq; // {cost, node}

    dist[start] = node_wei[start];
    pq.emplace(dist[start], start);
    while (!pq.empty()){
        auto[d, curr] = pq.top();
        pq.pop();

        if (dist[curr] < d) continue;

        for (pll& edge : adj[curr]){
            auto[edge_cost, next] = edge;
            ll new_d = d + edge_cost + node_wei[next];

            if (new_d < dist[next]){
                dist[next] = new_d;
                pq.emplace(new_d, next);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    node_wei.push_back(0);
    for (int i=0; i<n; ++i){
        int tmp;
        cin >> tmp;
        node_wei.push_back(tmp);
    }

    for (int i=0; i<m; ++i){
        ll u, v, b;
        cin >> u >> v >> b;
        adj[u].emplace_back(b, v);
        adj[v].emplace_back(b, u);
    }

    dijk(1, n);

    for (int i=2; i<=n; ++i)
        cout << dist[i] << " ";
}