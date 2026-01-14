#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int arr[n];
    for (int& i : arr)
        cin >> i;

    int ans = arr[0], sum = arr[0];
    for (int i=1; i<n; ++i) {
        sum = max(arr[i], sum+arr[i]);
        ans = max(ans, sum);
    }
    cout << ans;
}