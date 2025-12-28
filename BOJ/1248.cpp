#include <iostream>
#include <vector>
using namespace std;

vector<char> v;
vector<int> ans;
vector<vector<char>> s;
int n;

bool check(int idx) {
    int sum = 0;
    for (int i=idx; i>=0; --i) {
        sum += ans[i];
        if (s[i][idx] == '+' && sum <= 0) return false;
        if (s[i][idx] == '-' && sum >= 0) return false;
        if (s[i][idx] == '0' && sum != 0) return false;
    }
    return true;
}

bool solve(int idx) {
    if (idx == n) return true;

    for (int i=-10; i<11; ++i) {
        ans[idx] = i;
        if (check(idx))
            if (solve(idx+1)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    v.resize(n*(n+1)/2);
    ans.resize(n);
    for (char& c : v)
        cin >> c;

    int cnt = 0;
    s.resize(n, vector<char>(n));
    for (int i=0; i<n; ++i)
        for (int j=i; j<n; ++j)
            s[i][j] = v[cnt++];

    solve(0);

    for (int i : ans)
        cout << i << " ";
}
/*
void compensate(int start) {
    for (int i=start; i<n; ++i) {
        if (ans[i] > 0)
            ans[i]++;
        else if (ans[i] < 0)
            ans[i]--;
    }
}

void check(int start, int lim, int step) {
    int sum = 0;
    for (int i=start; i<start+lim; ++i) {
        sum += ans[step];
        if (sum > 0 && v[i] != '+') {
            compensate(step);
        }
        else if (sum < 0 && v[i] != '-') {
            compensate(step);
        }
        else if (sum == 0 && v[i] != '0') {
            compensate(step);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    v.resize(n*(n+1)/2);
    ans.resize(n);
    for (char& c : v)
        cin >> c;

    int sum = 0;
    for (int i=0; i<n; ++i) {
        if (v[i] == '+')
            ans[i] = abs(sum)+1;
        else if (v[i] == '-')
            ans[i] = -abs(sum)-1;
        else
            ans[i] = 0-sum;
        sum += ans[i];
    }

    int start = 0;
    for (int i=n, j=1; i>1; i--, j++) {
        start += i;
        check(start, i-1, j);
    }


    for (int i : ans)
        cout << i << " ";
}
*/