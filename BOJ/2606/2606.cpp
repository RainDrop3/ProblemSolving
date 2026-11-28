#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
queue<int> q;
vector<int> visited(101, 0);

int main(){
    int n, cnt;
    cin >> n >> cnt;

    adj.assign(n+1, {});
    while(cnt--){
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    q.push(1);
    visited[1] = 1;
    int ans = 0;
    while(!q.empty()){
        int num = q.front();
        q.pop();

        for(int i : adj[num]){
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);
                ans++;
            }
        }
    }

    cout << ans;
}