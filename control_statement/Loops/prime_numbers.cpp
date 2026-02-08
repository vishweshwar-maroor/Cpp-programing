// to produce prime number till n
#include<iostream>
using namespace std;
int main()
{
    int n ,z=0;
    cout <<"put n";
    cin>>n; //till waht number to check
    for(int i=2;i<=n;i++)
    { z=0;
        for(int j=2;j<i;j++)
    {
        if(i%j==0){z=1; break;}// identification of prime
    }
    if(z==0)cout<<i<<endl; //printing of the number
    

    }
}