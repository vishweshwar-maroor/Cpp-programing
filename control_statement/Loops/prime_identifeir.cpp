#include<iostream>
using namespace std;
int main()
{
    int n,z=0;
    cout<<"put number ";
    cin>>n;
    for(int i=2;i<n;i++)
    {
        if(n%i==0){z=1; break;}
    }
    if(z==0)cout<<"prime";
    else cout<<"not prime";
}