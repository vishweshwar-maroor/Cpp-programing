#include <iostream>
#include<vector>
#include<string>
#include<functional>
using namespace std;
int add(int x,int y){
    return x+y;
}
int sun(int x,int y){
return x-y;}
int main()
{
    int x=5,y=6;
    vector<char> sym={'+','-'};
    vector<function<void(int x,int y)>> fun={add,sub};
    cout<<fun[0];
}
