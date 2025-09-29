#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int cnt;
    cin >> cnt;
    vector <double> x1(cnt), y1(cnt), r1(cnt), x2(cnt), y2(cnt), r2(cnt);
    for (int i = 0; i < cnt; ++i) {
        cin >> x1[i] >> y1[i] >> r1[i] >> x2[i] >> y2[i] >> r2[i];
    }

    for (int i = 0; i < cnt; ++i) {
        double d = sqrt(pow(x2[i]-x1[i], 2) + pow(y2[i]-y1[i], 2));

        if(d == 0) { //두 점의 좌표 같을 때
            if(r1[i] == r2[i])  cout << -1 << endl;
            else                cout << 0 << endl;
        }
        else if(d < r1[i] || d < r2[i]){ // 작은 원이 큰 원에 포함
            double small, big;
            if(r1[i] < r2[i]){ small = r1[i]; big = r2[i]; }
            else {small = r2[i]; big = r1[i]; }

            if(big > d+small) cout << 0 << endl;
            else if(big == d+small) cout << 1 << endl;
            else if(big < d+small) cout << 2 << endl;
        }
        else{ //두 원이 각각 존재
            if(d > r1[i]+r2[i]) cout << 0 << endl;
            else if(d == r1[i]+r2[i]) cout << 1 << endl;
            else if(d < r1[i]+r2[i]) cout << 2 << endl;
        }

    }
}