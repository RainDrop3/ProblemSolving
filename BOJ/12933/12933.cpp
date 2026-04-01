#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<stack<char>> v(s.size());
    int ans = 0;
    bool possible = true;
    for(char c : s){
        switch (c){
            case 'q':
                for(int i=0; i<s.size(); ++i){
                    if(v[i].size()%5 == 0){
                        v[i].push(c);
                        break;
                    }
                }
                break;
            case 'u':
                for(int i=0; i<s.size(); ++i){
                    if(v[i].size()%5 == 1){
                        v[i].push(c);
                        break;
                    }
                    if(i == s.size()-1)
                        possible = false;
                }
                break;
            case 'a':
                for(int i=0; i<s.size(); ++i){
                    if(v[i].size()%5 == 2){
                        v[i].push(c);
                        break;
                    }
                    if(i == s.size()-1)
                        possible = false;
                }
                //cout << "c: " << c << " flag: " << flag << endl;
                break;
            case 'c':
                for(int i=0; i<s.size(); ++i){
                    if(v[i].size()%5 == 3){
                        v[i].push(c);
                        break;
                    }
                    if(i == s.size()-1)
                        possible = false;
                }
                break;
            case 'k':
                for(int i=0; i<s.size(); ++i){
                    if(v[i].size()%5 == 4){
                        v[i].push(c);
                        break;
                    }
                    if(i == s.size()-1)
                        possible = false;
                }
                break;
            default:
                break;
        }
        
    }
    for(auto s : v){
        if(s.size() % 5 == 0 && s.size() != 0)
            ans++;
        else if(s.size() % 5 != 0)
            possible = false;
    }
    if(ans == 0 || !possible)
        cout << -1;
    else
        cout << ans;
}