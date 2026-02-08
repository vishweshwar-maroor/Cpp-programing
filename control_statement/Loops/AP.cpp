#include<iostream>
using namespace std;
int main()
{
    int a,d,n;
    cout<<"put first term , common difference,no of terms ";
    cin>>a>>d>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<a+(i-1)*d<<endl;
    }
}