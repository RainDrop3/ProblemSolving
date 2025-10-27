/*
 * stdout N K: 10<=N<=2^63, 1<=K<=1000
 * flip(i, j): 0 <= i <= j < N
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int K;
    cin >> N >> K;

    map<long long, int> flipped;
    while (K--) {
        long long lhs, rhs;
        cin >> lhs >> rhs;

        flipped[lhs]++;
        flipped[rhs+1]++;
    }

    long long cnt_of_substring = 0;
    long long cnt_of_one = 0;
    long long prev_idx = 0;
    bool isToggled = false;

    for (auto& [idx, val] : flipped) {
        if (val % 2 == 0) continue;

        isToggled = !isToggled;
        if (isToggled == false) {  // true->false: end of flipped substring
            cnt_of_substring++;
            cnt_of_one += (idx - prev_idx);
        }
        prev_idx = idx;
    }
    cout << cnt_of_substring << " " << cnt_of_one;
}