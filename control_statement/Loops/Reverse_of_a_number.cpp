#include<iostream>
using namespace std;
int main()
{
    int n,z;
    cout<<"put a number";
    cin>>n;
    while(n>0)
    {
        z=n%10;
        cout<<z;
        n=n/10;
    }
}