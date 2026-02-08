#include<iostream>
#include<algorithm>
#include<vector>
void nextPermutation(vector<int> &v){
    int m=v.size()-1;
    for(m=v.size()-1;m>=0;m--){
        if(v[i]>v[i-1]){
            break;
        }
    }
    cout<<m;
    return;
}
using namespace std;
int main(){
    vector<int> v={1,5,8,4,7,6,5,3,1};
    nextPermutation(v);
}