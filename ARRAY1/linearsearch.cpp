#include<iostream>
using namespace std;
int main(){
    int arr[15];
    cout<<"put elements :";
    for(int i=0;i<=14;i++){ //input
        cin>>arr[i];
    }
    cout<<"put element you want to search";
    int n;
    cin>>n;
    for(int i=0;i<=14;i++){
        if(arr[i]==n){cout <<i+1<<" "<<arr[i]<<endl;} //Search and output
    }

}