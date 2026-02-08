/*Take positive integer input and tell if it
is a three digit number or not.*/
#include<iostream>
using namespace std;
int main()
{
    char ch;
    cout<<"put a character :";
    cin>>ch;
    int n=(int)ch;

    if((n>=65&&n<=90)||(n>=97&&n<=122)){cout<<"character is an alphabet";}  //[65,90]=A to Z  [97,122]= a to z
    else cout<<"character is an alphabet";
}