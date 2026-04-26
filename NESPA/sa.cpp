// Used Gemini to ask how to find maximum in 'LOCAL' segment
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int s, d, g;
string s1, s2;

int sa(char x, char y){
    if(x == y)
        return s;
    else
        return -d;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> d >> g >> s1 >> s2;

    int ans = -1;
    vector<vector<int>> v(s1.size()+1, vector<int>(s2.size()+1, 0));
    for(int i=1; i<=s1.size(); ++i){
        for(int j=1; j<=s2.size(); ++j){
            int match = v[i-1][j-1] + sa(s1[i-1], s2[j-1]);
            int gap1 = v[i-1][j] - g;
            int gap2 = v[i][j-1] - g;
            v[i][j] = max({0, match, gap1, gap2});

            ans = max(ans, v[i][j]);
        }
    }

    cout << ans;
}