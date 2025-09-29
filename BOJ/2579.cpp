#include <iostream>
using namespace std;

int main() {
    int cnt, score[301], dp[301];

    cin >> cnt;
    for (int i = 1; i <= cnt; ++i) cin >> score[i];

    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    dp[3] = max(score[1], score[2]) + score[3];
    for (int i = 4; i <= cnt; ++i) dp[i] = max(dp[i-2]+score[i], dp[i-3]+score[i-1]+score[i]);

    cout << dp[cnt];
}
