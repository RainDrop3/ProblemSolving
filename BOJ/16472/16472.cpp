#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string st;
    cin >> n >> st;

    vector<int> alphabet(26, 0);
    set<char> s;
    int left = 0, right = 0, length = 1;
    s.insert(st[0]);
    alphabet[st[0] - 'a']++;
    while(++right < st.size()){
        int idx = st[right] - 'a';
        alphabet[idx]++;
        s.insert(st[right]);
        
        while(s.size() > n){
            idx = st[left] - 'a';
            alphabet[idx]--;
            //cout << "left: " << left << " right: " << right << " length: " << length << endl;
            //cout << alphabet[idx] << endl;
            if(alphabet[idx] == 0)
                s.erase(st[left]);
            left++;
        }
        length = max(length, right - left + 1);
        //cout << "left: " << left << " right: " << right << " length: " << length << endl;
    }
    cout << length;
}