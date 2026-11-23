#include <iostream>
#include <vector>
using namespace std;

int n, m, maxi = 0, r1, c1;
vector<vector<int>> v, visited;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int r, int c, int sum, int depth) {
    if (depth > 3) {
        if (sum > maxi) maxi = sum;
        return;
    }
    for (int i=0; i<4; ++i) {
        int nr = r+dx[i], nc = c+dy[i];
        if (nr < 0 || nr > n-1 || nc < 0 || nc > m-1)
            continue;
        if (visited[nr][nc])
            continue;

        visited[nr][nc] = 1;
        sum += v[nr][nc];
        dfs(nr, nc, sum, depth+1);
        sum -= v[nr][nc];
        visited[nr][nc] = 0;
    }
}

void T_shape(int r, int c, int sum) {
    int cnt = 0, mini = 10e8;
    for (int i=0; i<4; ++i) {
        int nr = r+dx[i], nc = c+dy[i];
        if (nr < 0 || nr > n-1 || nc < 0 || nc > m-1)
            continue;
        cnt++;
        sum += v[nr][nc];
        if (v[nr][nc] < mini) mini = v[nr][nc];
    }
    if (cnt == 4)
        if (sum - mini > maxi) maxi = sum - mini;
    if (cnt == 3) {
        if (sum > maxi) maxi = sum;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    v.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<int>(m, 0));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            r1 = i, c1 = j;
            cin >> v[i][j];
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            visited[i][j] = 1;
            dfs(i, j, v[i][j], 1);
            visited[i][j] = 0;

            T_shape(i, j, v[i][j]);
        }
    }
    cout << maxi;
}