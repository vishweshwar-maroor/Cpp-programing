#include<iostream>
using namespace std;
int main()
{
   int a,b,n=1;
   cout<<"put a and b";
   cin>>a>>b;
   for(int i=1;i<=b;i++)
   {
    n=n*a;
   }
   cout<<"a^b ="<<n;
}