#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

stack<int> s;
queue<int> q;
vector<vector<int>> v;
vector<bool> flag;
vector<int> indeg;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ans.clear();
        int n;
        cin >> n;

        //팀 순위 입력
        for (int i=0; i<n; ++i) {
            int num;
            cin >> num;
            s.push(num);
        }

        //그래프 생성
        v.assign(n+1, vector<int>());
        flag.assign(n+1, false);
        indeg.assign(n+1, 0);
        while (!s.empty()) {
            flag[s.top()] = true;
            for (int i=1; i<=n; ++i) {
                if (!flag[i]) {
                    v[i].push_back(s.top());
                    indeg[s.top()] += 1;
                }
            }
            s.pop();
        }
/*
        for (auto i : v) {
            for (int j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
        for (int i=1; i<=n; ++i) {
            cout << indeg[i] << " ";
        }
        cout << "=========" << endl;
*/
        //순서 바꾸기
        int m;
        cin >> m;
        while (m--) {
            int a, b;
            cin >> a >> b;

            auto ita = find(v[b].begin(), v[b].end(), a); //b -> a
            if (ita != v[b].end()) { //b -> a
                v[a].push_back(b);
                v[b].erase(ita);
                indeg[b] += 1;
                indeg[a] -= 1;
            }
            else {
                auto itb = find(v[a].begin(), v[a].end(), b); //a -> b
                if (itb != v[a].end()) { //a -> b
                    v[b].push_back(a);
                    v[a].erase(itb);
                    indeg[a] += 1;
                    indeg[b] -= 1;
                }
            }

        }
/*
        for (auto i : v) {
            for (int j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
        for (int i=1; i<=n; ++i) {
            cout << indeg[i] << " ";
        }
        cout << endl;
*/
        //최종순위 예측
        flag.assign(n+1, false);
        ans.reserve(n+1);
        for (int i=1; i<=n; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
                flag[i] = true;
            }
        }

        //if (q.empty()) cout << "IMPOSSIBLE";

        while (!q.empty()) {
            for (int i : v[q.front()]) {
                //cout << i << ":" << indeg[i] << endl;
                indeg[i] -= 1;
                if (indeg[i] == 0) {
                    q.push(i);
                    flag[i] = true;
                }
            }
            ans.push_back(q.front());
            q.pop();
        }

        if (ans.size() != n)
            cout << "IMPOSSIBLE\n";
        else {
            for (int i : ans)
                cout << i << " ";
            cout << '\n';
        }
    }
}