#include<iostream>
#include<vector>
using namespace std;
int SUM(int* arr,int size,int sum=0){
    if(size==1){
        return sum+arr[0];
    }
    sum=SUM(arr+1,size-1,sum);
    return sum+arr[0];
    
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<SUM(arr,n);

}