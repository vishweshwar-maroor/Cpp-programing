#include<iostream>
using namespace std;
int main()
{
    int i=1 ,n=64;
    while(i<=26)
    {
        char ch =(char)n+i;
        cout<<ch<<" -> "<<n+i<<endl;
        i++;

    }
}