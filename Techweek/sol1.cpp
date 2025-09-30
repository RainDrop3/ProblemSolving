#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, tmp;
    vector<int> cnt, red, blue, purple;

    cin >> T;
    while (T--) {
        cnt.resize(2);
        for (int i=0; i<2; i++) {
            cin >> tmp;
            cnt[i] = tmp;
        }

        //cout << "cnt[0]: " << cnt[0] << " cnt[1]: " << cnt[1] << endl;
        red.resize(cnt[0]);
        blue.resize(cnt[1]);
        purple.resize(cnt[0]+cnt[1]);
        for (int i=0; i<cnt[0]; i++) {
            cin >> tmp;
            red[i] = tmp;
            purple[i] = tmp;
            //cout << "red tmp: " << tmp << endl;
        }
        for (int i=0; i<cnt[1]; i++) {
            cin >> tmp;
            blue[i] = tmp;
            purple[i+cnt[0]] = tmp;
            //cout << "blue tmp: " << tmp << endl;
        }

        sort(red.begin(), red.end());
        sort(blue.begin(), blue.end());
        sort(purple.begin(), purple.end());


        int N = purple.size();
        if (N % 2 == 0) {
            //cout << "purple[n/2]: " << purple[(N/2)-1] << endl;
            if (find(red.begin(), red.end(), purple[(N/2)-1]) != red.end() && find(blue.begin(), blue.end(), purple[(N/2)-1]) != blue.end()) {
                cout << "RB" << '\n';
            }
            else if (find(red.begin(), red.end(), purple[(N/2)-1]) != red.end()) cout << "R" << '\n';
            else if (find(blue.begin(), blue.end(), purple[(N/2)-1]) != blue.end()) cout << "B" << '\n';
            else cout << "error" << endl;
        }
        else {
            //cout << "purple[n/2 + 1]: " << purple[((N+1)/2)-1] << endl;
            if (find(red.begin(), red.end(), purple[((N+1)/2)-1]) != red.end() && find(blue.begin(), blue.end(), purple[((N+1)/2)-1]) != blue.end()) {
                cout << "RB" << '\n';
            }
            else if (find(red.begin(), red.end(), purple[((N+1)/2)-1]) != red.end()) cout << "R" << '\n';
            else if (find(blue.begin(), blue.end(), purple[((N+1)/2)-1]) != blue.end()) cout << "B" << '\n';
            else cout << "error" << endl;
        }

    }


}