#include<iostream>
using namespace std;
int main()
{
    int n,a=1,b=1 ,z;
    cout <<"put number greater than 2 ";
    cin>>n;
    cout<<1<<endl<<1<<endl;
    for(int i=3;i<=n;i++) 
    {
        z=a+b;
        cout<<z<<endl;

        a=b;b=z;
    }
    
}