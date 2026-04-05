#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v;
    while(n--){
        int tmp;
        cin >> tmp;

        auto it = lower_bound(v.begin(), v.end(), tmp);
        if(it == v.end())
            v.push_back(tmp);
        else
            *it = tmp;
    }

    cout << v.size();
}