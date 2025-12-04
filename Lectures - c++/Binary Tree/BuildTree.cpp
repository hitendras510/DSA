#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Global index for preorder traversal
int preIdx = 0;

// Search value in inorder array
int search(vector<int>& inorder, int left, int right, int val) {
    for (int i = left; i <= right; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree using preorder + inorder
Node* buildHelper(vector<int>& preorder, vector<int>& inorder, int left, int right) {
    if (left > right) return NULL;

    int curr = preorder[preIdx++];
    Node* root = new Node(curr);

    int inIdx = search(inorder, left, right, curr);

    root->left = buildHelper(preorder, inorder, left, inIdx - 1);
    root->right = buildHelper(preorder, inorder, inIdx + 1, right);

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    preIdx = 0;
    return buildHelper(preorder, inorder, 0, inorder.size() - 1);
}

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Node* root = buildTree(preorder, inorder);

    cout << "Tree Built Successfully!" << endl;
    return 0;
}
