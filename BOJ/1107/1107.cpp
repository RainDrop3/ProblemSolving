#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    vector<bool> broken(10, false);
    cin >> N >> M;

    //예외
    if(N == 100){
        cout << 0;
        return 0;
    }
    if(M == 10){
        cout << abs(N-100);
        return 0;
    }

    //입력
    for(int i=0; i<M; ++i){
        int tmp;
        cin >> tmp;
        broken[tmp] = true;
    }

    //brute force
    int ans = abs(N-100);
    for(int i=N; i<1e6; ++i){
        bool invalid = false;
        int cnt = 0;
        string s = to_string(i);

        for(char c : s){
            cnt++;
            if(broken[c - '0']){
                invalid = true;
                break;
            }
        }
        if(!invalid){
            ans = min(ans, abs(N - i) + cnt);
            break;
        }
    }
    for(int i=N; i>=0; --i){
        bool invalid = false;
        int cnt = 0;
        string s = to_string(i);

        for(char c : s){
            cnt++;
            if(broken[c - '0']){
                invalid = true;
                break;
            }
        }
        if(!invalid){
            ans = min(ans, abs(N - i) + cnt);
            break;
        }
    }

    cout << ans;
}