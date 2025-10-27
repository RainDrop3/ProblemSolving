/*
 * 4<=N<=100, 2<=k<=10, 1<=w<=20
 * ------------------
 * [tie break]
 * 1. 계산대의 대기시간이 같을 때: 작은 번호부터
 * 2. 손님이 동시에 나올 때: 큰 번호부터
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Customer {
    int id, items;
    Customer(int i, int it)
        :id(i), items(it) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k;
    cin >> N >> k;

    vector<queue<Customer>> counter(k);
    queue<Customer> waiting;
    while (N--) {
        int id, items;
        cin >> id >> items;
        waiting.emplace(id, items);
    }

    while (true) {
        //손님 빈 counter로 입장
        int mini = 21;
        for (auto& q : counter) {
            if (q.empty() && !waiting.empty()) {
                q.push(waiting.front());
                waiting.pop();
            }
            if (!q.empty() && q.front().items < mini) mini = q.front().items;
        }

        //계산시간 가장 적은 손님의 시간만큼 계산
        for (auto& q : counter) {
            if (!q.empty()) q.front().items -= mini;
        }

        //계산 완료된 손님 내보내기
        for (auto q=counter.rbegin(); q!=counter.rend(); ++q) {
            if (!q->empty() && q->front().items == 0) {
                cout << q->front().id << '\n';
                q->pop();
            }
        }

        //모든 counter가 비면 종료
        bool isEmpty = true;
        for (auto& q : counter) {
            if (!q.empty() || !waiting.empty()) isEmpty = false;
        }
        if (isEmpty) break;
    }
}