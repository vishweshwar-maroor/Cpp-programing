#include<iostream>
#include<vector>
using namespace std;
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void sort1(vector<int>& v){
    int low=0,mid=0,high=v.size()-1;
    while(mid<=high){
        if(v[high]==2)high--;
        if(v[low]==0){low++;mid++;};
        if(v[mid]==2){swap(mid,high);high--;};
        if(v[mid]==0){swap(low, mid);low++;mid++;};
        if(v[mid]==1){mid++;};
    }
}
int main(){
    vector<int> v={1,0,2,0,2,1,0,2,1,2,0,1,2,1,0,0,1,2};
    sort1(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
    
}