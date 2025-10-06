#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int find_set(int n, vector<int>& v) {
    if (v[n] == n) return n;
    return v[n] = find_set(v[n], v);
}

void union_set(int a, int b, vector<int>& v) {
    a = find_set(a, v);
    b = find_set(b, v);
    if (a != b) v[a] = v[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n+1);
    iota(v.begin(), v.end(), 0);

    while (m--) {
        int command, a, b;
        cin >> command >> a >> b;
        if (command == 0) {
            union_set(a, b, v);
        }
        else {
            if (find_set(a, v) == find_set(b, v)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}