//Heigt of Bst
#include<iostream>
using namespace std;

struct Bst{
    public:
    int data;
    Bst* left;
    Bst* right;

    Bst *root, *temp, *ttemp,*P;
    void init(){
        root = temp = ttemp = P = NULL;
    }
};

void createRoot(int x, Bst* &root){
    root = new Bst;
    root->data = x;
    root->left = root->right = NULL;
}

void AddNode(int x, Bst* root, Bst* &temp, Bst* &ttemp, Bst* &P){
    temp = root;
    while(temp!=NULL){
        ttemp=temp;
        if(temp->data > x)
            temp=temp->left;
        else
            temp=temp->right;
    }

    P = new Bst;
    P->data = x;
    P->left = P->right = NULL;
      if(ttemp->data > x)
        ttemp->left = P;
    else
        ttemp->right = P;
}

//Height
int height(Bst* root){
    if(root == NULL) return 0;
    int leftht=height(root->left);
    int rightht=height(root->right);
    return max(leftht, rightht)+1;
}

int main(){


    Bst obj;
    obj.init();

 
    createRoot(100, obj.root);

    
    AddNode(50,  obj.root, obj.temp, obj.ttemp, obj.P);
    AddNode(200, obj.root, obj.temp, obj.ttemp, obj.P);
    AddNode(20,  obj.root, obj.temp, obj.ttemp, obj.P);
    AddNode(80,  obj.root, obj.temp, obj.ttemp, obj.P);
    AddNode(10,  obj.root, obj.temp, obj.ttemp, obj.P);
    AddNode(30,  obj.root, obj.temp, obj.ttemp, obj.P);
    AddNode(25,  obj.root, obj.temp, obj.ttemp, obj.P);
    AddNode(150, obj.root, obj.temp, obj.ttemp, obj.P);
    AddNode(300, obj.root, obj.temp, obj.ttemp, obj.P);
    AddNode(110, obj.root, obj.temp, obj.ttemp, obj.P); 
    AddNode(170, obj.root, obj.temp, obj.ttemp, obj.P);

 cout << "Height of BST = " << height(obj.root) << endl;

}