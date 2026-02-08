#include<iostream>
using namespace std;
int product(int &x,int &y){
    int z=x*y;
    return z;

}
int main(){
    int a,b;
    cout<<"put two number";
    cin>>a>>b;
    cout<<product(a,b);
}