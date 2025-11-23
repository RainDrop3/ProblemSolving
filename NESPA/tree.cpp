#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    string value;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(string& val)
        :value(val){}
};

struct Tree {
    unordered_map<string, Node*> nodes;
    unordered_map<string, bool> isChild;
    Node* root = nullptr;

    Node* getNode(string& s) {
        if (s == "-") return nullptr;
        if (!nodes.count(s))
            nodes[s] = new Node(s);
        return nodes[s];
    }

    void insert(string& c, string& p, string& flag) {
        Node* parent = getNode(p);
        Node* child = getNode(c);
        if (flag == "1")
            parent->left = child;
        else
            parent->right = child;
        isChild[c] = true;
    }

    void insert2(string& p, string& l, string& r) {
        Node* parent = getNode(p);
        Node* lc = getNode(l);
        Node* rc = getNode(r);

        parent->left = lc;
        parent->right = rc;

        if (lc) isChild[lc->value] = true;
        if (rc) isChild[rc->value] = true;
    }

    void determineRoot() {
        for (auto& it : nodes) {
            string name = it.first;
            if (!isChild[name]) {
                root = it.second;
                break;
            }
        }
    }

    Node* getRoot() { return root; }

    void preOrder(Node* r) {
        if (!r) return;
        cout << r->value << " ";
        preOrder(r->left);
        preOrder(r->right);
    }

    void inOrder(Node* r) {
        if (!r) return;
        inOrder(r->left);
        cout << r->value << " ";
        inOrder(r->right);
    }

    void postOrder(Node* r) {
        if (!r) return;
        postOrder(r->left);
        postOrder(r->right);
        cout << r->value << " ";
    }

};

int main() {
    int N;
    cin >> N;
    //N--;

    Tree T;
    string s1, s2, s3;
    while (N--) {
        cin >> s1 >> s2 >> s3;
        if (s3 == "1" || s3 == "2") {
            T.insert(s1, s2, s3);
        }
        else {
            T.insert2(s1, s2, s3);
        }
    }

    T.determineRoot();
    T.preOrder(T.getRoot());
    cout << endl;
    T.inOrder(T.getRoot());
    cout << endl;
    T.postOrder(T.getRoot());
}

/*
vector<pair<int, int>> v(26, {-1, -1});

void preOrder(int n) {
    if (n>26 || n<0) return;

    cout << static_cast<char>(n + 'A');
    preOrder(v[n].first);
    preOrder(v[n].second);
}

void inOrder(int n) {
    if (n>26 || n<0) return;

    inOrder(v[n].first);
    cout << static_cast<char>(n + 'A');
    inOrder(v[n].second);
}

void postOrder(int n) {
    if (n>26 || n<0) return;

    postOrder(v[n].first);
    postOrder(v[n].second);
    cout << static_cast<char>(n + 'A');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    while (N--) {
        char c, p, flag;
        cin >> c >> p >> flag;

        if (flag == '1' || flag == '2') {
            int c_idx = c - 'A', p_idx = p - 'A';
            if (flag == '1')
                v[p_idx].first = c_idx;
            else
                v[p_idx].second = c_idx;
        }
        else {
            char parent = c, lc = p, rc = flag;
            v[parent-'A'] = {lc-'A', rc-'A'};
        }
    }

    preOrder(1);
}
*/