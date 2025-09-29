#include <iostream>
using namespace std;

int cnt, num[101], oper[5], tmp[101], sum;
int maxi = -1000000000;
int mini = 1000000000;

void cal(int k){
    if(k == cnt-1 && sum > maxi) maxi = sum;
    if(k == cnt-1 && sum < mini) mini = sum;
        if(oper[0] != 0){
            tmp[k] = sum;
            sum += num[k+1];
            oper[0]--;
            cal(k+1);
            oper[0]++;
            sum = tmp[k];
        }
        if(oper[1] != 0){
            tmp[k] = sum;
            sum -= num[k+1];
            oper[1]--;
            cal(k+1);
            oper[1]++;
            sum = tmp[k];
        }
        if(oper[2] != 0){
            tmp[k] = sum;
            sum *= num[k+1];
            oper[2]--;
            cal(k+1);
            oper[2]++;
            sum = tmp[k];
        }
        if(oper[3] != 0){
            tmp[k] = sum;
            sum /= num[k+1];
            oper[3]--;
            cal(k+1);
            oper[3]++;
            sum = tmp[k];
        }
    return;
}

int main(){
    cin >> cnt;
    for (int i = 0; i < cnt; ++i) cin >> num[i];
    for (int i = 0; i < 4; ++i) cin >> oper[i];

    sum = num[0];
    cal(0);
    cout << maxi << endl << mini;
}