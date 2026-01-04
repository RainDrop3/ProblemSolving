#include <iostream>
#include <vector>
#include <set>
using namespace std;
using pii = pair<int, int>;

int n, m, ans = 1e9;
vector<vector<char>> v;
set<pii> walls;
set<pair<pii, pii>> record;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

bool isFallen(pii p) {
    return (p.first >= n) || (p.first < 0)
        || (p.second >= m) || (p.second < 0);
}

void move(pii o1, pii o2, int cnt) {
    cnt++;
    if (cnt > 10) return;
    if (cnt >= ans) return;
    for (int i=0; i<4; ++i) {
        pii n_o1 = {o1.first+dr[i], o1.second+dc[i]},
            n_o2 = {o2.first+dr[i], o2.second+dc[i]};

        //cout << "[i] " << i << " / cnt: " << cnt << endl;
        //cout << "n_o1: " << n_o1.first << ", " << n_o1.second << endl;
        //cout << "n_o2: " << n_o2.first << ", " << n_o2.second << endl;
        //cout << isFallen(n_o1) << " " << isFallen(n_o2) << endl;

        //벽 부딪혔나
        bool iso1Crash = walls.count({n_o1.first, n_o1.second}),
             iso2Crash = walls.count({n_o2.first, n_o2.second});
        if (iso1Crash && iso2Crash)
            continue;
        if (iso1Crash) n_o1 = o1;
        if (iso2Crash) n_o2 = o2;

        //가지치기
        if (record.count({n_o1, n_o2}))
            continue;

        //하나만 떨어졌나
        if (isFallen(n_o1) != isFallen(n_o2)) {
            ans = min(ans, cnt);
            //cout << "=============ans: " << ans << ", cnt: " << cnt << endl;
            return;
        }
        //둘 다 떨어졌나
        if (isFallen(n_o1) && isFallen(n_o2))
            continue;

        record.emplace(n_o1, n_o2);
        move(n_o1, n_o2, cnt);
        record.erase({n_o1, n_o2});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    v.resize(n, vector<char>(m));
    pii o1 = {-1, -1}, o2 = {-1, -1};
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> v[i][j];
            if (v[i][j] == 'o') {
                if (o1.first == -1) {
                    o1.first = i;
                    o1.second = j;
                }
                else {
                    o2.first = i;
                    o2.second = j;
                }
            }
            else if (v[i][j] == '#')
                walls.emplace(i, j);
        }
    }

    move(o1, o2, 0);

    if (ans > 10)
        cout << -1;
    else
        cout << ans;
}