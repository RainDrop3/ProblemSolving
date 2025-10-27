#include <iostream>
#include <vector>
using namespace std;
int k, t, cycle = 0;

struct Robot {
    pair<int, int> pos;
    int target_idx;
    bool clockwise;
};

// 거리 계산 함수
int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// 로봇 이동 함수
void move(Robot& robot, vector<pair<int, int>>& points) {
    pair<int, int> target_pos = points[robot.target_idx];
    if (robot.pos.first == target_pos.first) {
        if (robot.pos.second < target_pos.second) robot.pos.second++;
        else robot.pos.second--;
    } else {
        if (robot.pos.first < target_pos.first) robot.pos.first++;
        else robot.pos.first--;
    }
}

//target_idx 갱신 함수
void SetTargetIdx(bool clockwise, int& target_idx) {
    if (clockwise) target_idx = target_idx + 1;
    else           target_idx = target_idx - 1 + k;
    target_idx %= k;
}

int main() {
    // 입력
    cin >> k;
    vector<pair<int, int>> point(k);
    for (int i = 0; i < k; i++) cin >> point[i].first >> point[i].second;
    cin >> t;

    // 시간 계산
    for (int i = 0; i < k; i++) cycle += dist(point[i], point[(i + 1) % k]);
    t %= 2 * cycle;

    // 로봇의 초기위치,방향 설정
    Robot c1, c2;
    c1.pos = point[0];
    c1.clockwise = true;
    c1.target_idx = 1;

    int c1_start_idx, c2_start_idx = k/2-1;
    c2.pos = point[c2_start_idx];
    c2.clockwise = false;
    c2.target_idx = (c2_start_idx - 1 + k) % k;

    // 로봇의 이동 및 충돌
    bool isDistOne = false;
    for (int i = 0; i < t; i++) {
        // 거리 1로 충돌했었으면 1초동안 안 움직임
        if (isDistOne) {
            isDistOne = false;
            continue;
        }

        // 로봇이 꼭짓점에 도달 시 target_idx 갱신
        if (c1.pos == point[c1.target_idx]) SetTargetIdx(c1.clockwise, c1.target_idx);
        if (c2.pos == point[c2.target_idx]) SetTargetIdx(c2.clockwise, c2.target_idx);

        // 로봇 이동
        move(c1, point);
        move(c2, point);

        //두 로봇이 같은 선분에 있는지 검사(교차점 및 평행하는 거리가 1인 두 선상에서의 충돌 판정 방지용)
        if (c1.clockwise) {
            c1_start_idx = c1.target_idx - 1 + k;
            c2_start_idx = c2.target_idx + 1;
        }
        else {
            c1_start_idx = c1.target_idx + 1;
            c2_start_idx = c2.target_idx - 1 + k;
        }
        c1_start_idx %= k;
        c2_start_idx %= k;

        // 충돌 여부 확인 (거리가 1 이하인가 && 두 로봇은 같은 선분에 있는가)
        if (dist(c1.pos, c2.pos) <= 1 && ((c1_start_idx == c2.target_idx && c2_start_idx == c1.target_idx) || c1.target_idx == c2.target_idx)) {
            // 방향 전환
            c1.clockwise = !c1.clockwise;
            c2.clockwise = !c2.clockwise;

            // 방향이 전환되었으므로 target_idx 갱신
            SetTargetIdx(c1.clockwise, c1.target_idx);
            SetTargetIdx(c2.clockwise, c2.target_idx);

            // 거리 1로 충돌
            if (dist(c1.pos, c2.pos) == 1) isDistOne = true;
        }
    }
    // 출력
    cout << c1.pos.first << " " << c1.pos.second <<
    endl << c2.pos.first << " " << c2.pos.second << endl;
}
