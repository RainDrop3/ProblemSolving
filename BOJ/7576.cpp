#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//접근 가능한 인덱스인지 확인
bool IsValid(const int y, const int x, const int size_y, const int size_x, const vector<vector<int>>& box) {
    if (x < 0 || x >= size_x) return false;
    if (y < 0 || y >= size_y) return false;
    if (box[y][x] != 0) return false;

    return true;
}

//토마토 익히기
void make1(queue<pair<int, int>>& q, vector<vector<int>>& box, const int m, const int n, int& days) {
    if (q.size() == 0) return;
    const int size = q.size();

    //주변 토마토 익히기
    for (int i=0; i<size; ++i) {
        if (IsValid(q.front().first+1, q.front().second, n ,m, box)) {
            box[q.front().first+1][q.front().second] = 1;
            q.push({q.front().first+1, q.front().second});
        }
        if (IsValid(q.front().first-1, q.front().second, n ,m, box)) {
            box[q.front().first-1][q.front().second] = 1;
            q.push({q.front().first-1, q.front().second});
        }
        if (IsValid(q.front().first, q.front().second+1, n ,m, box)) {
            box[q.front().first][q.front().second+1] = 1;
            q.push({q.front().first, q.front().second+1});
        }
        if (IsValid(q.front().first, q.front().second-1, n ,m, box)) {
            box[q.front().first][q.front().second-1] = 1;
            q.push({q.front().first, q.front().second-1});
        }
        q.pop();
    }

    days++;
    make1(q, box, m, n, days);
}

int main() {
    ios::sync_with_stdio();
    cin.tie(nullptr);

    int m, n, days = 0;
    cin >> m >> n;
    vector<vector<int>> box(n, vector<int>(m));
    queue<pair<int, int>> point;

    //입력, 1이 있는 좌표 저장
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> box[i][j];
            if (box[i][j] == 1) point.push({i, j});
        }
    }

    //토마토 익히기
    make1(point, box, m, n, days);

    //함수 종료 후 전체 탐색으로 0 찾기
    //0이 있다 : -1출력, 0이 없다 : 날짜 출력
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (box[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << days-1;
}