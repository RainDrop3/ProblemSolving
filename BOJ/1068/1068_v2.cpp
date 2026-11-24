#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int del;

int dfs(int cur){
    int cnt = 0, leaf = 0;
    for(int nxt : adj[cur]){
        if(nxt == del) continue;
        leaf += dfs(nxt);
        cnt++;
    }
    if(cnt == 0)
        return 1;
    else
        return leaf;

}

int main(){
    int n, root = -1;
    cin >> n;

    adj.assign(n, {});
    for(int i=0; i<n; ++i){
        int p; 
        cin >> p;
        if(p == -1)
            root = i;
        else
            adj[p].push_back(i);
    }
    
    cin >> del;
    if(del == root)
        cout << 0;
    else
        cout << dfs(root);

}