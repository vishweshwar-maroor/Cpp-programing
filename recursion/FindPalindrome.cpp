#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void Reverse(int start,int end ,string& str){
    if(start>=end){
        return;
    }
    else{
        swap(str[start],str[end]);
        Reverse(start+1,end-1,str);
    }
}
bool CheckPalindrome(string& str,int start,int end){
    if(start>end){
        return true;
    }
    if(str[start]==str[end]){
        return CheckPalindrome(str,start+1,end-1);
    }
    else{
        return false;
    }
    
}
int main(){
    string str="abcba";
    
    cout<<CheckPalindrome(str,0,str.length()-1);
}