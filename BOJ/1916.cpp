#include <iostream>
#include <vector>
#include <map>
#include <queue>
#define INF 1e9
using namespace std;

vector<pair<int, int>> graph[1001];
vector<int> dist;

void dijk(int start) {
    priority_queue<pair<int, int>> pq; //cost, dest
    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (dist[now] < cost) continue;

        for (auto edge : graph[now]) {
            int next_node = edge.first;
            int next_cost = cost + edge.second;

            if (dist[next_node] > next_cost) {
                dist[next_node] = next_cost;
                pq.emplace(-next_cost, next_node);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    dist.resize(n+1, INF);
    int src, dest, cost;
    while (m--) {
        cin >> src >> dest >> cost;
        graph[src].emplace_back(dest, cost);
    }

    cin >> src >> dest;
    dijk(src);
    cout << dist[dest];
}