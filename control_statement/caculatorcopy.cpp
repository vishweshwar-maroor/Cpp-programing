#include<iostream>
using namespace std;
int main()
{
    int a,b;char op;
    cout<<"input ";
   
    
    cin>>a>>op>>b;
    cout<<"answer :";
    if(op=='+')cout<<a+b;
    if(op=='-')cout<<a-b;
    if(op=='*')cout<<a*b;
    if(op=='/')cout<<a/b;

}      