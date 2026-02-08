#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cout<<"put two strings :";
    getline(cin,s);
    getline(cin,t);
    if(s.size()!=t.size()){
        cout<<"not isomorphic";
        return 0;
    }
    bool flag=true;
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            if(s[j]==s[i]){
                if(t[j]!=t[i]){
                    flag=false;
                    break;
                }
            }
        }
    }
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            if(t[j]==t[i]){
                if(s[j]!=s[i]){
                    flag=false;
                    break;
                }
            }
        }
        if(flag==false) break;
    }

    if(flag){
        cout<<"isomorphic";
    }
    else{
        cout<<"not isomorphic";
    }


}