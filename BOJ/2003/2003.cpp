#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for(int& i : v)
        cin >> i;

    int left = 0, right = 0, ans = 0;
    while(left <= right && left < n){
        int sum = 0;
        for(int i=left; i<=right; ++i){
            sum += v[i];
        }

        if(sum == m){
            ans++;
            left++;
            if(right < n-1)
                right++;
        }
        else if(left == right || (sum < m && right < n-1))
            right++;
        else
            left++;
    }
    cout << ans;
}