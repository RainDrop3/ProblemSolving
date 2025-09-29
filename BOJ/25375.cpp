#include <iostream>
#include <vector>
using namespace std;
#define INT_MAX 2100000000;

int gcd(const int a, const int b) {
    //cout << "-------gcd-----------" << endl;
    int div;
    if (a > b) div = b+1;
    else       div = a+1;

    int gcd = 1;
    while(div != 0) {
        //cout << "div: " << div << endl;
        if (a % div == 0 && b % div == 0) gcd = div;
        div--;
    }
    //cout << "div: " << div << endl;
    //cout << "gcd: " << gcd << endl;
    return gcd;
}

int main() {
    int Q, a, b;
    vector<pair<int, int>> v;

    cin >> Q;
    v.reserve(Q);
    for (int i=0; i<Q; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    //x+y=b, y=b-x
    bool okay = false;
    for (int i=0; i<v.size(); ++i) {
        //cout << "i: " << i << endl;
        int x = v[i].second-1;
        while(x!=0) {
            // << "x: " << x << endl;
            //cout << "y: " << v[i].second-x << endl;
            if (gcd(x, v[i].second-x) == v[i].first) {
                cout << 1 << '\n';
                okay = true;
                break;
            }
            x--;
        }
        if (!okay) cout << 0 << '\n';
        okay = false;
    }
}