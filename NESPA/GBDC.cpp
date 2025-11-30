#include <iostream>
#include <map>
#include <set>
#include <functional>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<set<int>, set<int, greater<int>>> m;
    set<int> s;
    char command = ' ';
    while (true) {
        cin >> command;
        if (command == '$') break;

        int num;
        s.clear();
        if (command == 'R') {
            while (true) {
                cin >> num;
                if (num < 0) break;
                s.insert(num);
            }
            m[s].insert(num);
        }
        else {
            while (true) {
                cin >> num;
                if (num == 0) break;
                s.insert(num);
            }
            if (m.count(s))
                for (int i : m[s])
                    cout << i << " ";
            else
                cout << "None";
            cout << '\n';
        }
    }
}