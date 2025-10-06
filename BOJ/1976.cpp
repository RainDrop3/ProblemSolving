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
    if (a != b) v[a] = b;
}

int main() {
    int N, M, num;
    cin >> N >> M;

    vector<int> v(N+1), plan(M+1);
    iota(v.begin(), v.end(), 0);

    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            cin >> num;
            if (num == 1) union_set(i, j, v);
        }
    }

    for (int i=1; i<=M; ++i) {
        cin >> num;
        plan[i] = num;
    }
    for (int i=1; i<M; ++i) {
        if (find_set(plan[i], v) != find_set(plan[i+1], v)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}