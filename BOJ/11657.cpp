#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const long long INF = 18e9;

struct Edge {
    int u, v, w;
};
vector<Edge> edges;
vector<long long> dist;

bool bellmanford(int start, int V) {
    dist[start] = 0;
    for (int i=0; i<V; ++i) {
        bool updated = false;
        for (auto& e : edges) {
            auto [u, v, w] = e;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = true;

                if (i == V - 1) return true;
            }
        }
        if (!updated) break;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    dist.assign(n+1, INF);
    int src, dest, cost;
    while (m--) {
        cin >> src >> dest >> cost;
        edges.push_back({src, dest, cost});
    }

    if (bellmanford(1, n))
        cout << -1;
    else {
        for (int i=2; i<=n; ++i) {
            if (dist[i] == INF)
                cout << -1;
            else
                cout << dist[i];
            cout << '\n';
        }
    }
}