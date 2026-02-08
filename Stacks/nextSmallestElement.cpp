#include<iostream>
#include<stack>

using namespace std;
int* smallerArray(int* arr,int size,int* ans){
    stack<int> st;
    st.push(-1);
    
    for(int i=size-1;i>=0;i--){
        if(arr[i]>st.top()){
            ans[i]=st.top();
            st.push(arr[i]);
        }
        else{
            while(st.top()>arr[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(arr[i]);
        }
    }
    return ans;
}

int main(){
    int arr[]={4,5,2,10,8};
    
    int size=sizeof(arr)/sizeof(arr[0]);
    int ans[size];
    smallerArray(arr,size,ans);
    for(int i=0;i<size;i++){
        cout<<ans[i]<<" ";
    }

}