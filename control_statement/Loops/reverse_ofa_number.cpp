#include<iostream>
using namespace std;
int main()
{
    int n,m=0;
    cout<<"put a number";
    
    cin>>n;
    int a=n;
    while(n>0)
    {
        m=m+n%10;
        m=m*10;
        n=n/10;
    }
    cout<<m/10<<endl<<m/10+a;
}