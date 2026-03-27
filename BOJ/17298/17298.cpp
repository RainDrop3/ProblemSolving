#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    stack<int> s;
    vector<int> v(n);
    vector<int> NGE(n, -1);
    for(int& i : v)
        cin >> i;

    for(int i=0; i<n; ++i){
        while(!s.empty() && v[s.top()] < v[i]){
            NGE[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }

    for(int i : NGE)
        cout << i << " ";
}