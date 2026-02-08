#include<iostream>
using namespace std;
void pasctri(int n){
    int a=1;int b;
    for(int i=0;i<=n;i++)
    {a=1;
        for(int j=0;j<=i;j++)
        {
            cout<<a;
            a=((i-j)/(j+1))*a;
           
            
        }
        cout<<endl;
    }
}
int main()
{
    pasctri(6);
}