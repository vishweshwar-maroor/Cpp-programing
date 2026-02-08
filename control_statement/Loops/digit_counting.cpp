#include<iostream>
using namespace std;
int main()
{
    int n,z=0;
    cout <<"put a number";
    cin>>n;
    while(n>0)
    {
        n=n/10;
        z++;
    }
    cout<< "no of digit is "<<z;

}