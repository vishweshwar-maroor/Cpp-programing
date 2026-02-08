#include<iostream>
using namespace std;
int suma(int arr){
    int z=0;
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        z=z+ arr[i];
    }
    return z;
}
int main(){
    int n;
    int arr[n];
    cout<<"put the number of elements :";
    cin>>n;
    cout<<"put elements ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int suma=suma(arr);
    cout<<suma;
}