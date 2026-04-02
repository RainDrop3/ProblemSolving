#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, div, k, coupon;
    cin >> n >> div >> k >> coupon;

    vector<int> v(n);
    for(int& i : v)
        cin >> i;
    for(int i=0; i<k-1; ++i) //원순열 유지를 위해 k-1만큼 추가
        v.push_back(v[i]);

    int curr_div = 0;
    vector<int> cnt(div+1, 0);
    for(int i=0; i<k; ++i){
        if (cnt[v[i]]++ == 0)
            curr_div++;
    }
    
    int left = 0, right = k-1, ans = 0;
    while(true){
        int tmp = curr_div;
        if(cnt[coupon] == 0)
            tmp++;
        ans = max(ans, tmp);
        //cout << "right: " << right << " curr_div: " << curr_div << " coupon: " << cnt[coupon] << " ans: " << ans << endl;

        //Sliding Window 이동
        if(right == n+k-2) break;
        if(cnt[v[left]] == 1)
            curr_div--;
        cnt[v[left++]]--;
        if(cnt[v[right+1]] == 0)
            curr_div++;
        cnt[v[++right]]++;
    }
    cout << ans;
}