#include<iostream>
using namespace std;
int main()
{
    int n,z=1;
    cout<<"put n";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        z=z*i;
    } 
    cout<<"n! ="<<z;
}