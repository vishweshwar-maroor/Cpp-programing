#include<iostream>
using namespace std;
void revcot(int n){
    if(n==0){
        return ;
    }
    else{
        cout<<n<<" ";
        revcot(n-1);
        
    }
}
int main(){
    cout<<"put a number";
    int n;
    cin>>n;
    revcot(n);
}