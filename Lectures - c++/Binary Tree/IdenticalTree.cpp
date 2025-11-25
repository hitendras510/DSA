#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// build a tree
Node* buildTree(vector<int>& arr, int& i){
    if(i >= arr.size() || arr[i] == -1){
        i++;
        return NULL;
    }
    Node* root = new Node(arr[i]);
    i++;
    root->left = buildTree(arr, i);
    root->right = buildTree(arr, i);
    return root;
}

// main logic
bool identicalTree(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL || root2 == NULL) return false;

    return root1->data == root2->data &&
           identicalTree(root1->left, root2->left) &&
           identicalTree(root1->right, root2->right);
}

int main(){
    vector<int> dataoftree = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    
    int index1 = 0;
    int index2 = 0;

    Node* root1 = buildTree(dataoftree, index1);
    Node* root2 = buildTree(dataoftree, index2);

    if(identicalTree(root1, root2))
        cout << "Is Tree Identical : TRUE\n";
    else
        cout << "Is Tree Identical : FALSE\n";
}
