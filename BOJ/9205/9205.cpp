#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dist(int x1, int y1, int x2, int y2){
    return abs(x2-x1) + abs(y2-y1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;
    while(t--){
        pair<int, int> home, festival;
        vector<pair<int, int>> con;
        cin >> n;
        cin >> home.first >> home.second;
        vector<int> visited(n, 0);
        while(n--){
            int x, y;
            cin >> x >> y;
            con.emplace_back(x, y);
        }
        cin >> festival.first >> festival.second;

        queue<pair<int, int>> q;
        q.push(home);

        bool happy_flag = false;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            if(dist(x, y, festival.first, festival.second) <= 1000){
                happy_flag = true;
                break;
            }

            int idx = 0;
            for(auto[x1, y1] : con){
                if(dist(x1, y1, x, y) <= 1000 && !visited[idx]){
                    q.emplace(x1, y1);
                    visited[idx] = 1;
                }
                idx++;
            }
        }
        if(happy_flag)
            cout << "happy\n";
        else
            cout << "sad\n";
    }
}