#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;

    vector<int> v(n);
    for(int& i : v)
        cin >> i;

    sort(v.begin(), v.end());
    int low = 1, high = v.back() - v.front() + 1;
    while(low+1 < high){
        int mid = (low+high) / 2;
        int wifi = v.front(), cnt = 1;

        while(true){
            auto it = lower_bound(v.begin(), v.end(), wifi+mid);
            if(it == v.end())
                break;
            wifi = *it;
            cnt++;
        }

        if(cnt < c)
            high = mid;
        else
            low = mid;
    }
    cout << low;
}