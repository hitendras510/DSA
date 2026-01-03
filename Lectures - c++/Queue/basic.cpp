#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
Node* head;
Node* tail;

public:
Queue(){
head = tail = NULL;

}

void push(int data){
Node* newNode = new Node(data);

if(empty()){
    head = tail = newNode;
}else{
    tail->next = newNode;
    tail = newNode;
}

}
void pop(){
 if(empty()){
    cout<<"Queue is empty\n";
 }
 Node* temp = head;
 head = head->next;
 delete temp;
}

int front(){
 if(empty()){
    cout<<"Queue is empty\n";
 }
 return head->data;
}
bool empty(){
return head == NULL;
}


};

int main(){
Queue q1;
q1.push(1);
q1.push(2);
q1.push(3);
q1.push(4);
q1.push(5);
q1.pop();
cout<<q1.front();
}