#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n+1, 0);
    for (int i=1; i<=n; ++i) {
        int num;
        cin >> num;
        v[i] = v[i-1] + num;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << v[b] - v[a-1] << '\n';
    }
}