#include<iostream>
#include<vector>
using namespace std;
int main(){
    int no0=0,no1=0;
    vector<int> v({1,0,1,0,0,0,1,0,0,1,1,1,0,1,0});
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i]==0){no0++;}
        if(v[i]==1)no1++;
    }
        for (int i = 0; i < v.size(); i++)
    {
        if(i<no0){v[i]=0;}
        else v[i]=1;
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<< " ";
    }    
    
}