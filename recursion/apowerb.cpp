#include <iostream>
using namespace std;
int Power(int a, int b)
{
    if (b == 1)
    {
        return a;
    }
    else
    {
        return (a * Power(a, b - 1));
    }
}
int PowerOptimised(int a,int b){
    if(b==1){
        return a; 
    }
    if(b%2==0){
        int ans=PowerOptimised(a,b/2);
        return (ans*ans);
    }
    else{
        int ans=PowerOptimised(a,(b-1)/2);
        return (a*ans*ans);
    }
}
int main()
{
    cout<<PowerOptimised(7,11);
}