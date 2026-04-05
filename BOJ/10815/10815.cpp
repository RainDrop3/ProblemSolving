#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;

    vector<int> v(n);
    for(int& i : v)
        cin >> i;

    sort(v.begin(), v.end());
    cin >> m;
    while(m--){
        int tmp;
        cin >> tmp;

        auto it = lower_bound(v.begin(), v.end(), tmp);
        if(it == v.end() || *it != tmp)
            cout << 0 << " ";
        else
            cout << 1 << " ";
    }
}