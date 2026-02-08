#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cout<<"put three integer ";
    cin>>a>>b>>c;
    if(a>b && b>c){cout<< a<<" is greatest";}
    else if(b>c && c>a){cout<< b<<" is greatest";}
    else if(c>a && a>b){cout<< c<<" is greatest";}
    else if(a>c && c>b){cout<< a<<" is greatest";}
    else if(b>a && a>c){cout<< b<<" is greatest";}
    else if(c>b && b>a){cout<< c<<" is greatest";}
    

}