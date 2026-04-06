#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

void del(int n){
    v[n] = -2;
    for(int i=0; i<v.size(); ++i)
        if(v[i] == n)
            del(i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, node;
    cin >> n;

    v.resize(n, 0);
    for(int& i : v)
        cin >> i;
    cin >> node;

    //edge case: root를 지울 때
    if(v[node] == -1){
        cout << 0;
        return 0;
    }

    del(node);
    vector<int> freq(n, 0); //나를 부모로 하는 노드의 개수
    for(int i=0; i<n; ++i){
        if(v[i] == -1)  //root는 부모가 없음
            continue;
        else if(v[i] == -2) //지운 노드는 freq에도 지운걸로 표시
            freq[i] = -2;
        else
            freq[v[i]]++;
    }

    int ans = 0;
    for(int i : freq){
        //cout << i << " ";
        if(i == 0)
            ans++;
    }
    cout << ans;
}