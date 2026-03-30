#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<int> fibo(46, 0);
    fibo[0] = 0;
    fibo[1] = 1;
    
    for(int i=2; i<46; ++i){
        fibo[i] = fibo[i-1] + fibo[i-2];
        //cout << fibo[i] << endl;
    }

    int num;
    stack<int> s;
    while(t--){
        cin >> num;
        auto it = lower_bound(fibo.begin(), fibo.end(), num);
        int sum = 0;

        while(sum != num){
            if(*it + sum <= num){
                s.push(*it);
                sum += *it;
            }
            it--;
        }
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << '\n';
    }
}