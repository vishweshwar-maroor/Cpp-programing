#include<bits/stdc++.h>


using namespace std;
void InsertionSort(vector<int> &arr){
    int n=arr.size();
    
    
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(arr[j]>key&&j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    
}
int main(){
    vector<int> arr={3,4,2,44,87,56,21,44,6,45};
    
    InsertionSort(arr);
    
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }

}