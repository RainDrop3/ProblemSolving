#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, maxi = -10000000;
    cin >> n >> k;

    vector<int> v(n+1, 0);
    for (int i=1; i<=n; ++i) {
        int num;
        cin >> num;
        v[i] = v[i-1] + num;
    }

    for (int i=0; i<=n-k; ++i)
        maxi = max(maxi, v[k+i]-v[i]);
    cout << maxi;
}