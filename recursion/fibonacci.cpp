#include<iostream>
using namespace std;
int fibo(int n){
    if(n==1){return 1;}
    if(n==2){return 1;}
    int big= fibo(n-1)+fibo(n-2);
    cout<<big<<endl;
    return big;
    
}
int fiboser(int p){
    
}
int main(){
    cout << "put an integer";
    int n;
    cin>>n;
    cout<<fibo(n);

}