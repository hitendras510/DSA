#include<iostream>
#include<vector>
using namespace std;

int ans = 0;

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

// Build tree from preorder array
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

// Single-pass O(n) height + diameter
int height(Node* root) {
    if (root == NULL) return 0;

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    // Update global diameter
    ans = max(ans, leftHt + rightHt);

    return max(leftHt, rightHt) + 1;
}

int diameter(Node* root) {
    ans = 0;            // reset global
    height(root);       // this will compute diameter
    return ans;
}

int main() {
    vector<int> dataoftree = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int index = 0;

    Node* root = buildTree(dataoftree, index);

    cout << "Diameter of Tree: " << diameter(root) << endl;
}
