#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

struct file {
    string _name;
    int _addr, _size;
    file(string n, int a, int s) : _name(n), _addr(a), _size(s) {}
};

list<file> disk;
map<string, list<list<file>::iterator>> file_table;

auto find_contiguous_space(int size) {
    for (auto it = disk.begin(); it != disk.end(); ++it)
        if (it->_name == "_empty_" && it->_size >= size)
            return it;
    return disk.end();
}

void merge_empty_blocks() {
    for (auto it = disk.begin(); it != disk.end();) {
        auto next = it;
        ++next;
        if (next != disk.end() && it->_name == "_empty_" && next->_name == "_empty_") {
            it->_size += next->_size;
            disk.erase(next);
        } else
            ++it;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, size, capacity = 0;
    cin >> V;
    disk.emplace_back("_empty_", 0, V);

    string inst, name;
    while (cin >> inst && inst != "end") {
        if (inst == "write") {
            cin >> name >> size;

            if (file_table.count(name)) { cout << "error\n"; continue; }
            if (V - capacity < size) { cout << "diskfull\n"; continue; }

            capacity += size;
            auto space = find_contiguous_space(size);

            if (space != disk.end()) {
                int addr = space->_addr;
                auto it = disk.insert(space, file(name, addr, size));
                file_table[name].push_back(it);

                space->_addr += size;
                space->_size -= size;
                if (!space->_size) disk.erase(space);
            }
            else {
                int remain = size;
                for (auto it = disk.begin(); it != disk.end() && remain; ++it) {
                    if (it->_name != "_empty_") continue;
                    int chunk = min(remain, it->_size);

                    auto ins = disk.insert(it, file(name, it->_addr, chunk));
                    file_table[name].push_back(ins);

                    it->_addr += chunk;
                    it->_size -= chunk;
                    remain -= chunk;

                    if (!it->_size) {
                        it = disk.erase(it);
                        --it;
                    }
                }
            }
        }

        else if (inst == "delete") {
            cin >> name;
            if (!file_table.count(name)) { cout << "error\n"; continue; }

            for (auto it : file_table[name]) {
                capacity -= it->_size;
                it->_name = "_empty_";
            }

            file_table.erase(name);
            merge_empty_blocks();
        }

        else if (inst == "show") {
            cin >> name;
            if (!file_table.count(name)) { cout << "error\n"; continue; }

            for (auto it : file_table[name])
                cout << it->_addr << " ";

            cout << '\n';
        }

        else {
            int gap = 0;
            for (auto it = disk.begin(); it != disk.end();) {
                if (it->_name == "_empty_") {
                    gap += it->_size;
                    it = disk.erase(it);
                } else {
                    it->_addr -= gap;
                    ++it;
                }
            }

            if (V - capacity)
                disk.emplace_back("_empty_", capacity, V - capacity);

            for (auto it = disk.begin(); it != disk.end();) {
                auto next = it;
                ++next;
                if (next != disk.end() && it->_name != "_empty_" && it->_name == next->_name) {
                    it->_size += next->_size;
                    disk.erase(next);
                } else
                    ++it;
            }

            file_table.clear();
            for (auto it = disk.begin(); it != disk.end(); ++it)
                if (it->_name != "_empty_")
                    file_table[it->_name].push_back(it);
        }
    }
}
