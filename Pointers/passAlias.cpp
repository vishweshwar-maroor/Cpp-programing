#include<iostream>
using namespace std;
void swap(int* x,int* y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;

}
int main()
{
    int x,y;
    int* p=&x;
    int* q= &y;
    cout<<"put two number";
    cin>>x>>y;
    swap(p,q);
    cout<<x<<y;
}