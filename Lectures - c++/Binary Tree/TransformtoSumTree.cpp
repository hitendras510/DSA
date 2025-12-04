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

static int idx = -1;

Node* buildTree(vector<int>& preorder){
    idx++;
    if(idx >= preorder.size() || preorder[idx] == -1) 
        return NULL;

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int SumTree(Node* root){
    if(root == NULL) return 0;

    int leftSum = SumTree(root->left);
    int rightSum = SumTree(root->right);

    root->data += leftSum + rightSum; 
    return root->data;
}

int main(){
    idx = -1;   

    vector<int> preorderArr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(preorderArr);

    cout << "Before conversion: ";
    preorder(root);
    cout << endl;

    SumTree(root);   // <-- You forgot this!

    cout << "After conversion: ";
    preorder(root);
    cout << endl;

    return 0;
}
