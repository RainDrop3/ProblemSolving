#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
    string name;
    vector<int> report;

    int attendance = 0, total = 0, maxi = 0, cnt100 = 0, mini = 100;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k;
    vector<int> priority(5);
    vector<info> stu;

    //입력
    cin >> N >> k;
    for (int& i : priority) cin >> i;
    stu.resize(N);
    for (int i=0; i<N; ++i) {
        stu[i].report.resize(k);
        cin >> stu[i].name;
        for (int& j : stu[i].report) {
            cin >> j;
            if (j > 0) {
                stu[i].attendance++;
                stu[i].total += j;
                if (j < stu[i].mini) stu[i].mini = j;
                if (j > stu[i].maxi) stu[i].maxi = j;
                if (j == 100) stu[i].cnt100++;
            }
        }
        if (stu[i].attendance == 0) stu[i].mini = 0;
    }

    //정렬
    sort(stu.begin(), stu.end(), [&](info& a, info& b) {
        for (int i : priority) {
            int val_a, val_b;
            switch (i) {
                case 1: val_a = a.attendance; val_b = b.attendance; break;
                case 2: val_a = a.total; val_b = b.total; break;
                case 3: val_a = a.mini; val_b = b.mini; break;
                case 4: val_a = a.maxi; val_b = b.maxi; break;
                case 5: val_a = a.cnt100; val_b = b.cnt100; break;
            }
            if (val_a != val_b) return val_a > val_b;
        }
        return a.name < b.name;
    });
    for (int i=0; i<N; ++i) cout << stu[i].name << endl;
}