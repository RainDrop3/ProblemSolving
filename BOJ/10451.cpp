#include <iostream>
#include <vector>
using namespace std;

void find_cycle(int start, int cur, vector<int>& v, vector<int>& cycle) {
    if (start == v[cur]) {
        cycle[cur] = 1;
        return;
    }
    cycle[cur] = 1;
    find_cycle(start, v[cur], v, cycle);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    vector<int> v, cycle;
    cin >> T;

    while (T--) {
        int size, num;
        cin >> size;
        v.assign(size+1, 0);
        cycle.assign(size+1, 0);
        for (int i=1; i<=size; ++i) {
            cin >> num;
            v[i] = num;
        }

        int cnt = 0;
        for (int i=1; i<=size; ++i) {
            if (cycle[i] == 0) {
                find_cycle(i, i, v, cycle);
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}