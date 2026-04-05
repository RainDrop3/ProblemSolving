#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;

    vector<int> A(n);
    for(int& i : A)
        cin >> i;
    sort(A.begin(), A.end());

    cin >> m;
    while(m--){
        int tmp;
        cin >> tmp;

        auto it = lower_bound(A.begin(), A.end(), tmp);
        if(it == A.end())
            cout << 0 << '\n';
        else if(*it == tmp)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}