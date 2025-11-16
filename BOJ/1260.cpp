#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<bool> visited;
vector<vector<int>> arr;
queue<int> q;

void dfs(const int num) {
    if (visited[num] == true) return;

    cout << num << " ";
    visited[num] = true;

    for (const int& i : arr[num])
        dfs(i);


}

void bfs(const int num) {
    q.push(num);

    while (q.size() != 0) {
        cout << q.front() << " ";
        visited[q.front()] = true;

        for (int& i : arr[q.front()]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
        q.pop();
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    arr.resize(n+1);
    visited.resize(n+1, false);
    for (int i=1; i<=m; ++i) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i=1; i<=n; ++i)
        sort(arr[i].begin(), arr[i].end());

    dfs(v);
    fill(visited.begin(), visited.end(), false);
    cout << '\n';
    bfs(v);
}