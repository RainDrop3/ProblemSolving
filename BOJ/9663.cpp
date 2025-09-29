#include <iostream>
#include<cmath>
using namespace std;

int col[15], n, cnt = 0;

void queen(int x){
    if(n == x) cnt++;
    else{
        for (int i = 0; i < n; ++i) {
            col[x] = i;
            bool ok = true;
            for (int j = 0; j < x; ++j) {
                if(col[x]==col[j] || abs(col[x]-col[j])==abs(x-j)){
                    ok = false;
                    break;
                }
            }
            if(ok) queen(x+1);
        }
    }
}
int main(){
    cin >> n;
    queen(0);
    cout << cnt;
}