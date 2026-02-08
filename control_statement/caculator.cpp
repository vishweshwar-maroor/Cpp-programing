#include<iostream>
using namespace std;
int main()
{
    int n ,a,b;
    cout<<"input operation \n 1 add\n 2 sub \n 3 mul \n 4 div \n";
    cin>>n;
    cout<<"put two number";
    cin>>a>>b;
    cout<<"answer :";

    switch(n)
    {
        case 1:
        cout<<a+b;
        break;
        case 2:
        cout<<a-b;
        break;
        case 3:
        cout<<a*b;
        break;
        case 4:
        cout<<a/b;
        break;
    }
}