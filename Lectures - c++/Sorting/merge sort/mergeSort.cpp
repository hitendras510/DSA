#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,int st, int mid, int end){
    vector<int> temp;
    int i = st,j = end;
    while(i <= mid && j <= end){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int k = st; k <= end; k++){
        arr[k] = temp[k-st];
    }
}
void mergeSort(vector<int> &arr,int st, int end){
    int mid = st + (end-st)/2;

    mergeSort(arr,st,mid); //left half
    mergeSort(arr,mid+1,end); //right half

    merge(arr,st,mid,end);
}


int main(){
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    mergeSort(arr,0,arr.size()-1);
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}
