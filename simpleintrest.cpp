#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr={1,2,3,4};
    
    if(arr.begin()+5 ==arr.end()){
        cout<<"1";
    }
    else cout<<"-1";
    

}