#include<iostream>
using namespace std;
int main(){
    int arr[15];
    cout<<"put elements :";
    for(int i=0;i<=14;i++){ //input
        cin>>arr[i];
    }
    int Max=max(0,arr[0]);
    for(int i=0; i<=14;i++){ // search for max element
        Max=max(Max,arr[i]);

        
    }
    int sMax=max(0,arr[0]);//search for second largest element
    for(int i=0;i<=14;i++){
        if(arr[i]!=Max){
            sMax=max(sMax,arr[i]);
        }
    }
    cout<<"second max element is "<<sMax;


}