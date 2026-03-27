#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n+1);
    v[0] = -1;
    for(int i=1; i<=n; ++i)
        cin >> v[i];

    stack<int> s;
    for (int i = 1; i <= n; ++i) {
        while (!s.empty() && v[s.top()] < v[i])
            s.pop();

        if (s.empty()) 
            cout << 0 << " ";
        else 
            cout << s.top() << " ";
        
        s.push(i);
    }
}