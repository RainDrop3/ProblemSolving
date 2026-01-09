#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, dp[101][10] = {0, }, MAX = 1e9;
    cin >> n;

    for (int i=1; i<10; ++i)
        dp[1][i] = 1;
    dp[1][0] = 0;

    for (int i=2; i<=n; ++i) {
        for (int j=1; j<9; ++j) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MAX;
        }
        dp[i][0] = dp[i-1][1] % MAX;
        dp[i][9] = dp[i-1][8] % MAX;
    }

    long long ans = 0;
    for (int i=0; i<10; ++i)
        ans += dp[n][i];
    cout << ans % MAX;
}