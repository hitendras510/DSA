#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
//declare
// vector<int> a = {1,2,3,4,5};
// a.reserve(100);
// cout<<"Size : "<<a.size()<<endl<<"Capacity is: "<<a.capacity()<<endl;
// a.push_back(6);
// cout<<"Size after push back : "<<a.size()<<endl<<"Capacity is : "<<a.capacity()<<endl;

//since vector is a dynamically allocated data structure whenever we try to grow it by adding more elements it will create a new array and copy all the elements from the old array to the new array and delete the old array

vector<string> b(10,"abc"); //b(size, input)
cout<<b[5]<<endl;
//Access a vector
for(int i =0;i<b.size();i++){
    cout<<b[i]<<" ";
}
    

}