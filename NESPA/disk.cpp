/*
 * 10 <= V <= 100,000, 5 <= inst <= 100
 * write: 통저장, 분할저장, diskfull, error
 * delete: 삭제, error
 * show: 출력, error
 * compact: 압축
 *
 * struct FILE{name, addr, size};
 * list<FILE>
 * map<string, vector<{int, int}>>
 */
#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;

struct file {
    string name;
    int addr;
    int size;
    file(string n, int a, int s)
        :name(n), addr(a), size(s){}
};

int main() {
    int V;
    cin >> V;
    list<file*> disk;
    map<string, vector<pair<int, int>>> state;
    state["_empty_"].push_back({0, V});

    string inst = "";
    while (inst != "end") {
        string name;
        cin >> inst;
        if (inst == "write") {
            int size;
            cin >> name >> size;
            disk.push_back(new file(name, 0, size));
            cout << disk.front()->size;
        }
        else if (inst == "delete") {
            cin >> name;
        }
        else if (inst == "show") {
            cin >> name;
        }
        else if (inst == "compact") {

        }
    }
}