#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long n, l, r;
string s;

long long count_pairs(int k){
    if(k <= 0) return 0;

    long long total = 0;
    vector<int> freq(26, 0);

    for(int i=0; i<n; ++i){
        total += freq[s[i] - 'a'];
        freq[s[i] - 'a']++;
        if(i >= k)
            freq[s[i-k] - 'a']--;
    }
    return total;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l >> r >> s;
    cout << count_pairs(r) - count_pairs(l-1);
}