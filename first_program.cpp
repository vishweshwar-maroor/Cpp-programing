#include<iostream>
#include<vector>
using namespace std;
void vec(vector<int>::iterator left,vector<int>::iterator right){
    int i=0;
    while(left<right){
        cout<<*left <<" ";
        left++;
    }
}
int main()
{ 
    vector<int> v={1,2,3,4,5,6};
    vec(v.begin(),v.end());
    cout<<distance(v.begin(),v.end());
    
   
} 