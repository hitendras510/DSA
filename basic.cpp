#include<iostream>
using namespace std;


// prime

int main(){
    int n;
    cin>>n;

    int i = n;
    while (i<n)
    {
        if(n%i==0) {
            cout<<"not prime"<<endl;
        }
        else{
            cout<<"is prime"<<endl;
        }
        i=i+1;
    }
    
}