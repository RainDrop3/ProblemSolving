#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<ll>> v, cache;

ll solve(int r, int c){
    if(r >= n || c >= n) return 0;
    if(cache[r][c] != -1) return cache[r][c];
    if(r == n-1 && c == n-1) return 1;

    if(v[r][c] == 0){
        cache[r][c] = 0;
        return 0;
    }

    ll sum = solve(r, v[r][c]+c) + solve(v[r][c]+r, c);
    cache[r][c] = sum;
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    v.assign(n, vector<ll>(n, 0));
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> v[i][j];

    cache.assign(n, vector<ll>(n, -1));
    cout << solve(0, 0);

}