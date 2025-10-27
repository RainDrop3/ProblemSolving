#include <iostream>
#include <algorithm>
using namespace std;

struct table{
    string name;
    int money;
    bool operator>(const table& t) const{
        return this->money > t.money;
    }
};

int main(){
    int N;
    cin >> N;

    table t[N];
    for (int i = 0; i < N; ++i){
        cin >> t[i].name >> t[i].money;
    }

    sort(t, t+N, greater<table>());

    bool SamePrev = false;
    bool bid = false;                                       // 입찰자가 있는가
    for (int i = 0; i < N; ++i) {
        if(t[i].money == t[i+1].money) {SamePrev = true;}   // 다음 사람이랑 같은 금액일 때
        else if(SamePrev) {SamePrev = false;}               // 이전 사람이랑 같은 금액일 때
        else {                                              // 입찰
            cout << t[i].name;
            bid = true;
            break;
        }
    }
    if(!bid) cout << "NONE";                                // 유찰
}