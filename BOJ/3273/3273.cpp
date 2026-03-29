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

    int x;
    cin >> x;

    int left = 0, right = n-1, ans = 0;
    while(v[left] < v[right]){
        if(v[left] + v[right] == x){
            ans++;
            left++;
            right--;
        }
        else if(v[left] + v[right] < x)
            left++;
        else
            right--;
    }
    cout << ans;
}