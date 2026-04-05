#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long cut(long long h, vector<long long>& v){
    long long sum = 0;
    for(const long long& i : v)
        if(i > h)
            sum += (i-h);
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    vector<long long> trees(n);
    for(long long& i : trees)
        cin >> i;

    long long left=0, right=2e9, mid;
    while(left + 1 < right){
        mid = (left + right) / 2;
        //cout << "cut: " << cut(mid, trees) << endl;
        if(cut(mid, trees) < m)
            right = mid;
        else
            left = mid;

        //cout << "left: " << left << " right: " << right << endl;
    }
    cout << left;
}