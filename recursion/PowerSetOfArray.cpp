#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int> &arr,int i,vector<int> temp,vector<vector<int>> &ans){
    if(i>=arr.size()){
        ans.push_back(temp);
    }
    //Exclude
    solve(arr,i+1,temp,ans);
    //Include
    temp.push_back(arr[i]);
    solve(arr,i+1,temp,ans);

}
vector<vector<int>> PowerSet(vector<int> &arr){
    int i=0;
    vector<int> temp;
    vector<vector<int>> ans;
    return ans;

}
int main(){
    vector<int> arr={1,2,3};
    vector<vector<int>> ans=PowerSet(arr);

}