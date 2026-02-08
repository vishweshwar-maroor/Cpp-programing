#include<iostream>
using namespace std;
void LCM(int a, int b){
    for(int i=1;1;i++){
        if(i%a==0 &&i%b==0){cout<<i; break;}
    }
}
int main(){
    LCM(25,35);
}