#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long Q, a, b;
    cin >> Q;

    vector<pair<long long, long long>> v;
    v.reserve(Q);
    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        v.emplace_back(a, b);
    }

    for (int i = 0; i < Q; i++) {
        if (v[i].second % v[i].first == 0 && v[i].second / v[i].first >= 2) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}