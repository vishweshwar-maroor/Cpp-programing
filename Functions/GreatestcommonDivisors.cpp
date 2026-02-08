#include<iostream>
using namespace std;
void comdiv(int a,int b){
    for(int i=1;i<=min(a,b);i++){
        if(a%i==0 &&b%i==0){cout<<i<<endl;}
    }
}
void HCF(int a,int b){
    for(int i=min(a,b);i>0;i--){
        if(a%i==0 &&b%i==0){cout<<i; break;}
    }
}
int main()
{
   
    HCF(12,13);
}