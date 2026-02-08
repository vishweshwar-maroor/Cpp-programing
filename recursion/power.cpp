#include<iostream>
using namespace std;
int power(int m,int n){
    if(n>=1){
        m=m*power(m,n-1);
    }
    else{
        return 1;
    }
    return m;
}
int main(){
    cout<<"input base and power";
    int m,n;
    cin>>m>>n;
    cout<<power(m,n);


}