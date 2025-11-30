#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;
vector<int> indeg;
vector<vector<int>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    indeg.assign(n+1, 0);
    v.resize(n+1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        indeg[b] += 1;
        v[a].push_back(b);
    }
    for (int i=1; i<=n; ++i)
        if (indeg[i] == 0) q.push(i);

    while (!q.empty()) {
        for (int i : v[q.front()]) {
            indeg[i] -= 1;
            if (indeg[i] == 0) q.push(i);
        }
        cout << q.front() << " ";
        q.pop();
    }
}