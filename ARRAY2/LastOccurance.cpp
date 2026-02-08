#include<iostream>
#include<vector>
using namespace std;
int lastocc(int arr[],int size,int find){
    int z =-1; //to maintain index
    for(int i=0;i<size;i++){
        if(arr[i]==find){z=i;}

    }
    return z;

}
int lstocc(int arr[],int size,int find){
    int z=0; //to maintain index
    for(int i=size-1;i>=0;i--){
        if(arr[i]==find){z=i;break;}

    }
    return z;

}
int main(){
    int arr[]={5,6,8,2,6,7,5,4,89,2,1,8,6,7,48,5,4};
    int size= sizeof(arr)/sizeof(arr[0]); //size of array
    int find; //element needed to  be searched
    cout <<"put the element";
    cin>>find;
    // int index=lastocc(arr,size,find);
    // cout<<index+1;
    int index=lstocc(arr,size,find);
    cout<<index+1;
    

}