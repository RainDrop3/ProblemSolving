#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
vector<int> v;

int Find(int n) {
    //cout << "called Find" << endl;
    if (n == v[n]) return n;
    return v[n] = Find(v[n]);
}

bool Union(int a, int b) {
    //cout << "called Union" << endl;
    a = Find(a); b = Find(b);
    if (a == b) return false;

    if (a > b) v[a] = v[b];
    else       v[b] = v[a];
    return true;
}

bool Compare(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    return get<2>(a) < get<2>(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int>> info;
    int a, b, c;
    for (int i=0; i<M; ++i) {
        cin >> a >> b >> c;
        info.emplace_back(a, b, c);
    }

    sort(info.begin(), info.end(), Compare);

    int ans = 0;
    v.resize(N+1);
    iota(v.begin(), v.end(), 0);
    for (int i=0; i<M; ++i) {
        if (Union(get<0>(info[i]), get<1>(info[i])))
            ans += get<2>(info[i]);
        //cout << get<0>(info[i]) << ", " << get<1>(info[i]) << "), ans: " << ans << endl;

        //auto it = upper_bound(v.begin(), v.end(), 1);
        //if (it == v.end()) break;
    }
    cout << ans;
}