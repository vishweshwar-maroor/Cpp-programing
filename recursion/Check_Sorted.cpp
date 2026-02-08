#include<iostream>
#include<vector>
using namespace std;
bool Check_Sorted(int* arr,int size){
    if(size==0||size==1){
        return true;
    }
    if(arr[0] <= arr[1]){
        bool z=Check_Sorted(arr+1,size-1);
        return z;
    }
    else{
        return false;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool flag=Check_Sorted(arr,n);
    cout<<flag;

}