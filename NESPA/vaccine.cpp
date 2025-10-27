/*
 * old M - old F - child - adult F - adult M
 * 5<= N <=1000
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Person {
    int id, order;
    string age;
    char sex;

    Person(int i, int a, char s, int o)
        :id(i), sex(s), order(o) {
        if (a > 60)      age = "Old";
        else if (a > 15) age = "Adult";
        else             age = "Child";
    }
};

struct Compare {
    bool operator()(const Person& a, const Person& b) const {
        if (a.age != b.age) {
            if (a.age == "Adult") return true;
            if (a.age == "Child" && b.age == "Old") return true;
            return false;
        }
        if (a.sex != b.sex) {
            if (a.age == "Old" && b.age == "Old") {
                if (a.sex == 'F') return true;
                return false;
            }
            if (a.age == "Adult" && b.age == "Adult") {
                if (a.sex == 'M') return true;
                return false;
            }
        }
        return a.order > b.order;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, id, age;
    char sex;
    priority_queue<Person, vector<Person>, Compare> info;

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> id >> age >> sex;
        info.push({id, age, sex, i});
    }
    while (N--) {
        cout << info.top().id << '\n';
        info.pop();
    }
}