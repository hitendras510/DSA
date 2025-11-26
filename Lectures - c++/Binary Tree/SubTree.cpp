//is SubTree Tree of Another Tree.

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

//build tree
Node* buildTree(vector<int>& arr, int& i){
    if(i >= arr.size() || arr[i]==-1){
        i++;
        return NULL;
    }
    Node* root = new Node(arr[i]);
    i++;
    root->left = buildTree(arr, i);
    root->right = buildTree(arr, i);
    return root;
}

// Main logic:
// 1.check identical
bool isIdentical(Node* p, Node* q){
    if(p == NULL || q == NULL){
        return p ==q;
    }
    return p->data == q->data && isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
}

//2. check subtree of another tree
bool isSubTree(Node* root, Node* subRoot){
    if(root == NULL || subRoot == NULL){
        return root == subRoot;
    }
    if(root->data == subRoot->data && isIdentical(root,subRoot)){
        return true;
    }
    return isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
}

int main(){
    vector<int> dataoftree = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int index = 0;
    Node* root = buildTree(dataoftree, index);
    Node* subRoot = buildTree(dataoftree, index);

    if(isSubTree(root, subRoot))
        cout << "Is SubTree : TRUE\n";
    else
        cout << "Is SubTree : FALSE\n";
    return 0;
}
