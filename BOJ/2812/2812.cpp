#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    string num;
    cin >> n >> k >> num;

    stack<int> s;
    int cnt = 0;
    for(char c : num){
        int i = c - '0';
        
        while(!s.empty() && s.top() < i && cnt < k){
            s.pop();
            cnt++;
        }
        s.push(i);
    }
    while(cnt < k){
        s.pop();
        cnt++;
    }

    stack<int> s2;
    while(!s.empty()){
        s2.push(s.top());
        s.pop();
    }
    while(!s2.empty()){
        cout << s2.top();
        s2.pop();
    }
}