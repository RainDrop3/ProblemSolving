#include <iostream>
using namespace std;

int dp[1000001]; //memoization 배열

int rec(int n){
    if(n == 1) return 0;
    if(dp[n] != -1) return dp[n];

    int res = rec(n-1) + 1;
    if(n%2 == 0) res = min(res, rec(n/2)+1);
    if(n%3 == 0) res = min(res, rec(n/3)+1);

    return dp[n] = res;
}

int main(){
    int num;
    cin >> num;

    fill(dp, dp+1000001, -1);
    cout << rec(num);
}