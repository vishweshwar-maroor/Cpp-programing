#include<iostream>
using namespace std;
int factorial(int n){
    int a=1;
    for(int i=1;i<=n;i++)
    {
        a=a*i;
    }
    return a;
}
int NCR(int n,int r){
    int ncr;
    ncr=factorial(n)/(factorial(r)*factorial(n-r));
    return ncr;
}
int NPR(int n,int r){
    int npr=factorial(n)/factorial(n-r);
    return npr;
}
int main()
{
    cout<<NCR(5,2);
}