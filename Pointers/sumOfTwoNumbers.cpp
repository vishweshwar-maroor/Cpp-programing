#include<iostream>
using namespace std;
int main()
{
    int x=5,y=6;
    int *p1=&x,*p2=&y;
    cin>>*p1>>*p2;
    cout<<*p1<<*p2;

}