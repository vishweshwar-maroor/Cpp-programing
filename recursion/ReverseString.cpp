#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//void Swap(str)
void Reverse(int start,int end ,string& str){
    if(start>=end){
        return;
    }
    else{
        swap(str[start],str[end]);
        Reverse(start+1,end-1,str);
    }
}
int main(){
    string str="abcde";
    int length=str.size();
    Reverse(0,length-1,str);
    cout<<str;
}