#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define INF 1e9
using namespace std;

vector<int> d;
map<int, vector<pair<int, int>>> graph;

void dijkstra(int start) {
    priority_queue<pair<int ,int>> pq;
    pq.emplace(0, start);
    d[start] = 0;

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist) continue;

        for (auto e : graph[now]) {
            int cost = dist + e.second;
            if (cost < d[e.first]) {
                d[e.first] = cost;
                pq.emplace(-cost, e.first);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, k;
    cin >> v >> e >> k;

    d.resize(v+1, INF);
    for (int i=0; i<e; ++i) {
        int src, dest, cost;
        cin >> src >> dest >> cost;

        graph[src].emplace_back(dest, cost);
    }

    dijkstra(k);
    for (int i=1; i<=v; ++i) {
        if (d[i] == INF)
            cout << "INF";
        else
            cout << d[i];
        cout << '\n';
    }
}