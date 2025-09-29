#include <iostream>
using namespace std;

int main(){
    int dp[1001];
    dp[1] = 1;
    dp[2] = 2;

    int n;
    cin >> n;

    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    cout << dp[n]%10007;
}
/*
unsigned long long factorial(int n){
    unsigned long long res = 1;
    for(int i=1; i<=n; i++) res *= i;
    return res;
}

int main(){
    int n;
    unsigned long long sum = 0;
    cin >> n;

    for (int i = 0; i <= floor(n/2); ++i) { //i는 가로막대기set의 개수
        sum += factorial(i + n-2*i) / (factorial(i) * factorial(n-2*i)); // 같은 것이 있는 순열(n-2*i가 세로 막대 개수)
    }

    cout << sum%10007;
}*/
/*
int dp[1001];

int rec(int n){
    if(n<4) return n;
    if(dp[n] != -1) return dp[n];

    return dp[n] = rec(n-1) + 1;
}
int main(){
    int num;
    cin >> num;

    fill(dp, dp+1001, -1);
    cout << rec(num)%10007;
}
*/