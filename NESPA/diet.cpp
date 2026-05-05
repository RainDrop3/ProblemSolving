#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int k, pro, fat, car, vit;

struct Food{
    int pro, fat, car, vit, cost;
    Food(int p, int f, int c, int v, int co)
        :pro(p), fat(f), car(c), vit(v), cost(co){};
};

struct Comb{
    int cost, sum;
    vector<int> idx;
    Comb(int c, int s, vector<int>& v)
        :cost(c), sum(s), idx(v){};

    auto operator<(Comb& other) const{
        if (cost != other.cost)
            return cost < other.cost;
        if (sum != other.sum)
            return sum > other.sum;
        return idx < other.idx;
    }
};

stack<Food> s;
vector<Food> table;
vector<Comb> ans;
vector<int> index;
int curr_pro=0, curr_fat=0, curr_car=0, curr_vit=0, curr_cost=0;
void bt(int start){
    if (curr_pro >= pro && curr_fat >= fat && curr_car >= car && curr_vit >= vit){
        ans.emplace_back(curr_cost, curr_pro+curr_fat+curr_car+curr_vit, index);
        return;
    }
    if (start >= k)
        return;

    for (int i=start; i<k; ++i){
        s.emplace(table[i]);
        auto[p, f, c, v, cost] = s.top();
        curr_pro += p; curr_fat += f; curr_car += c; curr_vit += v; curr_cost += cost;
        index.push_back(i+1);

        bt(i+1);

        index.pop_back();
        curr_pro -= p; curr_fat -= f; curr_car -= c; curr_vit -= v, curr_cost -= cost;
        s.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> pro >> fat >> car >> vit;

    for (int i=0; i<k; ++i){
        int p, f, c, v, cost;
        cin >> p >> f >> c >> v >> cost;

        table.emplace_back(p, f, c, v, cost);
    }

    bt(0);
    sort(ans.begin(), ans.end());

    if (ans.empty())
        cout << 0;
    else{
        for (int i : ans[0].idx)
            cout << i << " ";
    }
}