#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(string val) : data(val) {}
};

Node* insert(Node* node, string val) {
    if (node == nullptr)
        return new Node(val);
    if (val < node->data)
        node->left = insert(node->left, val);
    else if (val > node->data)
        node->right = insert(node->right, val);
    return node;
}
Node* remove(Node* node, string val){
    if (node == nullptr) return nullptr;

    if (val < node->data)
        node->left = remove(node->left, val);
    else if (val > node->data)
        node->right = remove(node->right, val);
    else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }

        if (node->left != nullptr) {
            Node* tmp = node->left;;
            while (tmp->right != nullptr)
                tmp = tmp->right;
            node->data = tmp->data;
            node->left = remove(node->left, node->data);
        }
        else {
            Node* tmp = node->right;
            while (tmp->left != nullptr)
                tmp = tmp->left;
            node->data = tmp->data;
            node->right = remove(node->right, node->data);
        }
    }
    return node;
}
void depth(Node* node, int cur, int target, bool& found) {
    if (node == nullptr) return;

    depth(node->left, cur + 1, target, found);
    if (cur == target) {
        cout << node->data << " ";
        found = true;
    }
    depth(node->right, cur + 1, target, found);
}
void leaf(Node* node) {
    if (node == nullptr) return;

    leaf(node->left);
    if (node->left == nullptr && node->right == nullptr) {
        cout << node->data << " ";
    }
    leaf(node->right);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* root = nullptr;
    string inst, data;
    while (true) {
        cin >> inst;
        if (inst == "quit") break;

        if (inst == "+") {
            cin >> data;
            root = insert(root, data);
        }
        else if (inst == "-") {
            cin >> data;
            root = remove(root, data);
        }
        else if (inst == "depth") {
            cin >> data;
            bool found = false;
            depth(root, 1, stoi(data), found);
            if (!found) cout << "NO";
            cout << '\n';
        }
        else {
            leaf(root);
            cout << '\n';
        }
    }
}