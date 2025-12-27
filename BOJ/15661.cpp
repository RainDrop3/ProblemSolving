#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, mask, ans = 1e9;
vector<vector<int>> v, score;

int cal(int teams) {
    int a=0, b=0;
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            if (((1<<i)&teams) && ((1<<j)&teams))
                a += score[i][j];
            else if (!((1<<i)&teams) && !((1<<j)&teams))
                b += score[i][j];
        }
    }
    return abs(a-b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    mask = (1<<n) - 1;
    v.resize(n, vector<int>(n));
    score.resize(n, vector<int>(n, 0));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> v[i][j];
            if (i<j) score[i][j] += v[i][j];
            else score[j][i] += v[i][j];
        }
    }

    for (int i=1; i<mask; ++i) {
        if (i&1) {
            int diff = cal(i);
            if (diff < ans) ans = diff;
        }
    }
    cout << ans;
}