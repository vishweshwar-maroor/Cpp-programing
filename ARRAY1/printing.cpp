#include<iostream>
using namespace std;
int main(){
    int arr[5];
    for(int i=0;i<=4;i++){
        cout<<"put "<<i+1<<" number :";
        cin>>arr[i];
    }
    cout<<"elements are";
    for(int i=0;i<=4;i++){
        
        cout<<arr[i]<<endl;
    }
   
   
}