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

//build tree
Node* buildTree(vector<int>& arr, int& i){
    if( i >= arr.size() || arr[i] == -1){
    i++;
    return NULL;
}
Node* root = new Node(arr[i]);
root->left = buildTree(arr,i);
root->right = buildTree(arr,i);
return root;
}

//Main Logic
int countNode(Node* root){
    if( root == NULL){

        return 0;
    }
    int leftcount = countNode(root->left);
    int rightcount = countNode(root->right);
   
    return leftcount + rightcount + 1;
}

int main(){

    vector<int> data = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int index = 0;

    Node* root = buildTree(data, index);
    cout<<"Count of Nodes:"<<countNode(root)<<endl;
    return 0;
    
}