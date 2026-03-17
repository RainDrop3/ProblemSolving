#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, r, d, u;
    cin >> l >> r >> d >> u;

    int ans = 0;
    for(int i=l; i<=r; ++i){
        int maxi = max(abs(i), max(abs(u), abs(d)));
        
        if(maxi == abs(i))
            if(i%2 == 0)
                ans += u-d+1;
        else if(i%2 == 0){
            if(abs(u)>abs(i) && abs(d)>abs(i))
                ans += u-d+1;
            if(u>0)
                ans += (u-abs(i))/2;
            if(d<0)
                ans += (-d-abs(i))/2;
        }
        else{
            if(u>0)
                ans += (u-abs(i))/2;
            if(d<0)
                ans += (-d-abs(i))/2;
        }
                
    }
    cout << ans;
}