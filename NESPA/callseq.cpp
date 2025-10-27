#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>
#include <unordered_set>
using namespace std;
unordered_map<char, vector<string>> func;
vector<pair<char, string>> inst(1);
vector<int> visited(26);

bool isFunc(string& s) {
    if (s.size() == 1 && isupper(s[0])) return true;
    return false;
}

bool isCycle(char f) {
    visited[f - 'A'] = 1;
    char next_func;

    for (string& s : func[f]) {
        if (isFunc(s)) {
            next_func = s[0];
            if (visited[next_func - 'A'] == 1) return true;
        }

        if (visited[next_func - 'A'] == 0) {
            if (isCycle(next_func)) return true;
        }
    }

    visited[f - 'A'] = 2;
    return false;
}

void call(string s) {
    for (auto i : func[s[0]]) {
        if (isFunc(i)) {
            call(i);
            continue;
        }
        inst.push_back({s[0], i});
    }
    inst.pop_back(); //'$' 제거
}

void print(int idx) {
    if (idx > 0 && idx < inst.size()) cout << inst[idx].first << "-" << inst[idx].second;
    else if (idx < 0 && idx > -inst.size()) {
        auto it = inst.rbegin() - idx - 1;
        cout << it->first << "-" << it->second;
    }
    else cout << "NONE";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k1, k2;
    cin >> N >> k1 >> k2;

    //함수 입력
    unordered_set<char> used_func; //실제로 호출되는 함수 목록
    used_func.insert('M');
    while (N--) {
        string word;
        char func_name;

        cin >> func_name;
        while (word != "$") {
            cin >> word;
            func[func_name].push_back(word);
        }
    }

    //DEADLOCK 확인
    if (isCycle('M')) {
        cout << "DEADLOCK";
        return 0;
    }

    string ptr;
    while (ptr != "$") {
        for (auto i : func['M']) {
            if (isFunc(i)) {
                call(i);
                continue;
            }
            ptr = i;
            inst.push_back({'M', ptr});
        }
        inst.pop_back(); //'$' 제거
    }

    //출력
    print(k1);
    print(k2);

    return 0;
}