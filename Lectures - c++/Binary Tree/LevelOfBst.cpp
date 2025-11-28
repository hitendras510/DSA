#include<iostream>
using namespace std;

struct BST{
public:
    int data;
    BST* left;
    BST* right;

    BST *root, *temp, *ttemp,*P;

    void init(){
        root = temp = ttemp = P = NULL;
    }
};

void createRoot(int x, BST* &root){
    root = new BST;
    root->data = x;
    root->left = root->right = NULL;
}

void AddNode(int x, BST *root, BST* &temp, BST* &ttemp, BST* &P){
    temp = root;

    while(temp != NULL){
        ttemp = temp;
        if (temp->data > x){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }

    P = new BST;
    P->data = x;
    P->left = P->right = NULL;

    if(ttemp->data > x)
        ttemp->left = P;
    else
        ttemp->right = P;
}

// get level of a node
int getLevel(BST* root, int x) {
    int level = 1;

    while(root != NULL){
        if(root->data == x)
            return level;

        if(root->data>x)
            root = root->left;
        else
            root = root->right;

        level++;
    }

    return -1;
}

int main() {

    BST obj;
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

  
    cout << "Level of 50 - 200  = " << getLevel(obj.root, 200)  << endl;
    cout << "Level of 20-80-150-300  = " << getLevel(obj.root, 80)  << endl;
    cout << "Level of 10-30-110-170 = " << getLevel(obj.root, 170) << endl;
    cout << "Level of 25  = " << getLevel(obj.root, 25)  << endl;
    cout << "Level of 500 = " << getLevel(obj.root, 500) << endl;

    return 0;
}
