#include <iostream>
#include <string>
#include <iterator>
using namespace std;

int main() {
    istreambuf_iterator<char> begin(cin);
    istreambuf_iterator<char> end;
    string source_code(begin, end), transed_code;

    for (char w : source_code)
        if (w == '{' || w == '}')
            transed_code.push_back(w);

    int complexity = 0, depth = 1;
    for (char w : transed_code) {
        if (w == '{') {
            complexity += depth;
            depth++;
        }
        else
            depth--;
    }
    cout << complexity;
}