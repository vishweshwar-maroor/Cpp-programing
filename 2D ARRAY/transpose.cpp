#include<iostream>
using namespace std;
void swap(int &x,int &y){
    int temp=x;
    x=y;y=temp;
}
int main(){
    int n;
    cout<<"put size";
    cin>>n;
    int arr[n][n];
    cout<<"put elements";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    //transpose
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    //flip
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(arr[i][j],arr[i][n-1-j]);
        }
    }
    //print
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    
}