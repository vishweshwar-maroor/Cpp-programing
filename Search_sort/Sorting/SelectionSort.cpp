#include<bits/stdc++.h>
#include<vector>

using namespace std;
void SelectionSort(vector<int> &arr){
    int n=arr.size();
    int minIndex=0;
    for(int i=0;i<n-1;i++){
        minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}
int main(){

}