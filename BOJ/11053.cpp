#include <iostream>
using namespace std;

int main() {
    int n, arr[1001], dp[1001];
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    for (int i = 0; i < n; ++i) dp[i] = 1;

    int maxi = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    cout << maxi;
}

/*
int main(){
    int n, arr[1001], start, maxi = 1, len = 1;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n-1; ++i) {
        start = arr[i];
        len = 1;
        for (int j = i; j < n-1; ++j) {
            if(start < arr[j+1]) {
                start = arr[j+1];
                len++;
            }
        }
        if(maxi < len) maxi = len;
    }
    cout << maxi;
}
*/