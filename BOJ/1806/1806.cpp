#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    vector<int> v(n);
    for(int& i : v)
        cin >> i;

    int l = 0, r = 0, ans = 1e9;
    int sum = v[0];
    while(l <= r && r <= n-1){
        if(sum >= s){
            ans = min(ans, r-l+1);
            //cout << ans << ": " <<  l << " " << r << endl;
            if(l == r){
                r++;
                if(r < n)
                    sum += v[r];
            }
            else{
                l++;
                sum -= v[l-1];
            }
        }
        else if(r == n-1){
            l++;
            sum -= v[l-1];
        }
        else{
            r++;
            sum += v[r];
        }
    }

    if(ans == 1e9)
        cout << 0;
    else
        cout << ans;
}