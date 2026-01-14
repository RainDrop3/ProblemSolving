#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int dp[n+1];

    dp[0] = 0;
    for (int i=1; i<=n; ++i) {
        dp[i] = i;
        for (int j=1; j*j<=i; ++j)
            dp[i] = min(dp[i], dp[i-j*j]+1);
    }
    cout << dp[n];
}