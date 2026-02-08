#include<iostream>
using namespace std;
// void fnl(int &x){
//     int y=(x)%10;//last digit
//     while((x)>=10){x=x/10;}
//     cout<<x<<" "<<y;
// }
// int main()
// {
//     int x;
//     cout<<"put a number";
//     cin>>x;
//     cout<< "first and last digit are ";
//     fnl(x);
// }
void find(int n,int* p1,int* p2){
    *p1=n%10;
    while(n>9){n=n/10;}
    *p2=n;

}
int main(){
    int n,lastDigit,firstDigit;
    int* p1=&lastDigit;
    int* p2=&firstDigit;
    cout<<"put number";
    cin>>n;
    find(n,p1,p2);
    cout<<*p2<<" "<<*p1;
}

