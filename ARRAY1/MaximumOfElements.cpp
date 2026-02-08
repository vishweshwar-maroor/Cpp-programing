#include<iostream>
using namespace std;
int main(){
    int arr[15];
    cout<<"put elements :";
    for(int i=0;i<=14;i++){ //input
        cin>>arr[i];
    }
    int z=max(0,arr[0]);
    for(int i=0; i<=14;i++){ // search for max element
        z=max(z,arr[i]);

        
    }
    cout<<"max element is "<<z;


}