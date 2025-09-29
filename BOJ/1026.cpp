#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, tmp, sum = 0;
    vector<int> A, B;

    cin >> N;
    A.reserve(N);
    B.reserve(N);
    for (int i=0; i<N; ++i) {
        cin >> tmp;
        A.push_back(tmp);
    }
    for (int i=0; i<N; ++i) {
        cin >> tmp;
        B.push_back(tmp);
    }

    sort(B.begin(), B.end(), greater<int>());
    sort(A.begin(), A.end());

    for (int i=0; i<N; ++i) {
        sum += A[i] * B[i];
    }

    cout << sum;
}