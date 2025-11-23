//post traversal used

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
        left = NULL;
        right = NULL;
    }
};

//build tree;
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

//logic for Height of tree
int height(Node* root){
    if(root == NULL) return 0;
    int leftht=height(root->left);
    int rightht=height(root->right);
    return max(leftht, rightht)+1;
}

int main(){
vector<int> dataoftree = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
int index = 0;

Node* root = buildTree(dataoftree, index);

cout<<"Height of Tree: "<<height(root)<<endl;
return 0;

}