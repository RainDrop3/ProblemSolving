#include <iostream>
using namespace std;

int n, m;
int arr[10];
int isused[10];
void func(int k)
{
    if(k == m){
        for (int i = 0; i < m; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if(isused[i] == 0){
            arr[k] = i;
            isused[i] = 1;
        }
        else continue;
        func(k+1);
        isused[i] = 0;
    }
}

int main()
{
    cin >> n >> m;
    func(0);
}
/*
int main(){
    int N, M, arr[9];
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        arr[0] = i;
        for (int j = 1; j < M; ++j) {
            if(arr[j-1] != j) arr[j] = j; //사용한 적 없는 숫자면 사용
            else            arr[j] = j+1; //이미 앞에서 사용한 숫자면 +1
        }
    }
}
 */