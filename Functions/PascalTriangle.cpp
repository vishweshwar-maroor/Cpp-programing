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
void pastri(int n){
     
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<" "<<NCR(i,j)<<" ";
            
            
        }
        cout<<endl;

        
    }
}
int main()
{
    pastri(20);
    


    
}