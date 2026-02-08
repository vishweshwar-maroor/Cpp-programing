#include<iostream>
#include<array>
using namespace std;
int* BinarySearch(int* start, int* end, int key){
    auto mid=(start)+(end-start)/2;
    if(start>end){
        return NULL;
    }
    if(*mid==key)
    return mid;

    if(*mid>key){
        auto ans=BinarySearch(start,mid-1,key);
        return ans;
    }
    if(*mid<key){
        auto ans=BinarySearch(mid+1,end,key);
        return ans;
    }
}
int main(){
    int arr[5]={1,2,3,4,5};
    int* ans=BinarySearch(arr,arr+5,4);
    if(ans==NULL){
        cout<<"element not found";

    }
    else{
        cout<<"index "<<ans-arr;
    }


}