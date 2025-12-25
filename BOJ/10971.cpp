#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> w, dp;
const int INF = 1e9;
int n;

int TSP(int mask, int cur) {
    if (mask == (1 << n) - 1) {
        if (w[cur][0] != 0) return w[cur][0];
        return INF;
    }

    if (dp[mask][cur] != INF) return dp[mask][cur];

    for (int i=0; i<n; ++i) {
        if (mask & (1<<i) || w[cur][i] == 0) continue;
        dp[mask][cur] = min(dp[mask][cur], TSP(mask|(1<<i), i) + w[cur][i]);
    }
    return dp[mask][cur];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    w.resize(n, vector<int>(n, 0));
    dp.resize(1<<n, vector<int>(n, INF));
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            cin >> w[i][j];

    cout << TSP(1, 0);
}