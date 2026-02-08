#include<bits/stdc++.h>
#include<vector>

using namespace std;
void BubbleSort(vector<int> &arr){
    int n=arr.size();
    
    for(int i=0;i<n-1;i++){
        bool swapped=false;
        for(int j=i+1;j<n-1-i;j++){
            swap(arr[j],arr[j+1]);
            swapped=true;
        }
        if(swapped==false){
            break;
        }
        
    }
}
int main(){

}