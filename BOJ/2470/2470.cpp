#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for(int& i : v)
        cin >> i;
    sort(v.begin(), v.end());

    int left = 0, right = n-1;
    pair<int, int> ans;
    ans.first = v[left], ans.second = v[right];
    while(left < right){
        
        if(abs(v[left] + v[right]) < abs(ans.first + ans.second)){
            ans.first = v[left];
            ans.second = v[right];
        }

        if(v[left] + v[right] < 0)
            left++;
        else
            right--;
    }
    cout << ans.first << " " << ans.second;
}