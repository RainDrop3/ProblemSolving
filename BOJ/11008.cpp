#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    string a, b;
    vector<pair<string, string>> v;
    cin >> T;

    for (int i=0; i<T; ++i) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    if (a.find(&a.front(), a.back(), b))
}