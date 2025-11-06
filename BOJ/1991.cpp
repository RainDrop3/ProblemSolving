#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v(26, {-1, -1});

void preOrder(int n) {
    if (n>26 || n<0) return;

    cout << static_cast<char>(n + 'A');
    preOrder(v[n].first);
    preOrder(v[n].second);
}

void inOrder(int n) {
    if (n>26 || n<0) return;

    inOrder(v[n].first);
    cout << static_cast<char>(n + 'A');
    inOrder(v[n].second);
}

void postOrder(int n) {
    if (n>26 || n<0) return;

    postOrder(v[n].first);
    postOrder(v[n].second);
    cout << static_cast<char>(n + 'A');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    char p, cl, cr;
    while (N--) {
        cin >> p >> cl >> cr;
        int p_idx = p - 'A';
        int cl_idx = cl - 'A';
        int cr_idx = cr - 'A';

        v[p_idx] = {cl_idx, cr_idx};
    }

    preOrder(0);
    cout << endl;
    inOrder(0);
    cout << endl;
    postOrder(0);
}