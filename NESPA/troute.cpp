// GPT 도움: 비대칭(X,Y) 엣지 케이스 처리
// 같이 한 친구: 양윤성 박태훈 문수호 강민규 이도헌
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<string, pair<string,string>> tree;
unordered_map<string, int> firstPos, depth, inorderPos;
vector<pair<string, int>> euler;
int inorderIdx = 0;

void inorderTravel(string node) {
    if (node == "-" || node.empty()) return;
    inorderTravel(tree[node].first);
    inorderPos[node] = inorderIdx++;
    inorderTravel(tree[node].second);
}

void eulerTravel(string node, int d) {
    if (node == "-" || node.empty()) return;
    if (firstPos.find(node) == firstPos.end()) {
        firstPos[node] = euler.size();
        depth[node] = d;
    }
    euler.push_back({node, d});
    if (tree[node].first != "-") {
        eulerTravel(tree[node].first, d + 1);
        euler.push_back({node, d});
    }
    if (tree[node].second != "-") {
        eulerTravel(tree[node].second, d + 1);
        euler.push_back({node, d});
    }
}

string calcLCA(string start, string end) {
    int left = min(firstPos[start], firstPos[end]), right = max(firstPos[start], firstPos[end]), minDepth = 100;
    string lca = "";
    for (int i = left; i <= right; i++)
        if (euler[i].second < minDepth) minDepth = euler[i].second, lca = euler[i].first;
    return lca;
}

int main() {
    int n; cin >> n;
    string start, end, parent, left, right;
    unordered_set<string> parents, children;

    while(n--) {
        cin >> parent >> left >> right;
        parents.insert(parent);
        if (left != "-") children.insert(left);
        if (right != "-") children.insert(right);
        tree[parent] = {left, right};
    }
    cin >> start >> end;

    string root;
    for (const auto& p : parents)
        if (children.find(p) == children.end()) { root = p; break; }

    inorderTravel(root);
    if (inorderPos[start] > inorderPos[end]) swap(start, end);
    eulerTravel(root, 0);

    string lca = calcLCA(start, end);
    cout << depth[start] - depth[lca] << " " << depth[end] - depth[lca] << '\n';
}