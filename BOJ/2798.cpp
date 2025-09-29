#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> card(n);
    for (int i = 0; i < n; i++) cin >> card[i];

    int answer = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = card[i] + card[j] + card[k];
                if (sum <= m && sum > answer) {
                    answer = sum;
                }
            }
        }
    }
    cout << answer;
}

/*
vector<int> card;
int n, m, tmp, sum, maxi, depth = 0;

void cal(int k){
    if(depth == 3 && sum <= m){
        if(maxi < sum) maxi = sum;
        return;
    }
    for (int i = k; i < n; ++i) {
        sum += card[i];
        depth++;
        cal(i+1);
        depth--;
        sum -= card[i];
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        card.push_back(tmp);
    }

    cal(0);
    cout << maxi;
}*/