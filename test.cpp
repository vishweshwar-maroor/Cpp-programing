#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    
    unordered_map<int,bool> mp;
    mp[5]=true;
    cout<<mp[5];
}