#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> v(s1.size()+1, vector<int>(s2.size()+1, 0));
    int ans = 0;
    for(int i=0; i<s1.size(); ++i){
        for(int j=0; j<s2.size(); ++j){
            if(s1[i] == s2[j])
                v[i+1][j+1] = v[i][j] + 1;
            ans = max(ans, v[i+1][j+1]);
        }
    }

    cout << ans;
}