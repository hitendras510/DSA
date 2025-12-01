#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
}; // ← MISSING SEMICOLON FIXED HERE ✅

Node* buildTree(vector<int>& arr, int& i) {
    if (i >= arr.size() || arr[i] == -1) {
        i++;
        return NULL;
    }

    Node* root = new Node(arr[i]);
    i++;

    root->left = buildTree(arr, i);
    root->right = buildTree(arr, i);

    return root;
}

// Step 1: Level Order Traversal
// Step 2: Use map<hd, node>
// Step 3: Print map keys
void topView(Node* root) {
    if (!root) return;

    queue<pair<Node*, int>> q;   // <node, hd>
    map<int, int> m;             // <hd, node val>

    q.push({root, 0});

    while (!q.empty()) {
        Node* curr = q.front().first;
        int currHd = q.front().second;
        q.pop();

        // only store first node seen at each horizontal distance
        if (m.find(currHd) == m.end()) {
            m[currHd] = curr->data;
        }

        if (curr->left != NULL) {
            q.push({curr->left, currHd - 1});
        }

        if (curr->right != NULL) {
            q.push({curr->right, currHd + 1});
        }
    }

    for (auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    vector<int> data = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int index = 0;

    Node* root = buildTree(data, index);
    topView(root);

    return 0;
}
