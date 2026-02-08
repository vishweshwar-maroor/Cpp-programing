#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str="bhola";
    stack<char> st;
    for(auto i:str){
        st.push(i);

    }
    str="";
    for(;st.size()!=0;){
        str.push_back(st.top());
        st.pop();

    }
    cout<<str;
}