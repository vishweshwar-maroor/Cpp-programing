
#include <iostream>
#include<vector>

using namespace std;
int main()
{
    int num=8;
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    int j=4;
    while(j<100){
        bool flag=true;
        for(auto a: v){
            if(num%a==0){
                flag=false;
                break;
            }
        }
        if(flag==true){
            v.push_back(num);
            
            j++;
        }
        num++;

    }
    for(auto a: v){
        cout<<a<<" ";
    }
    cout<<v.size();
}