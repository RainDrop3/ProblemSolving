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

        auto l_it = lower_bound(v.begin(), v.end(), tmp);
        auto u_it = upper_bound(v.begin(), v.end(), tmp);

        if(l_it == v.end() || *l_it != tmp)
            cout << 0 << " ";
        else
            cout << u_it - l_it << " ";
    }
}