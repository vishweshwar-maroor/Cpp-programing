#include<iostream>
using namespace std;
int main()
{
    int n,z=0;
    cout<<"put number";
    cin>>n;
    while(n>0)
    {
        z=z+(n%10);
        n=n/10;


    }
    cout<<"the sum of digit of the number is "<<z;
}