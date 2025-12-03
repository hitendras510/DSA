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
Node* buildTree(vector<int> preorder){
    idx++;

    if(preorder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

//main logic
void kthLevel(Node* root, int k){
  if(root == NULL){
    return;
  }   
  if( k == 1){
    cout<<root->data<<" ";
    return;
  }

  kthLevel(root->left, k-1);
  kthLevel(root->right, k-1);
}

int main(){
    vector<int> preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(preorder);
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<"The kth level of the tree is: ";
    kthLevel(root, k);
    return 0;
}






