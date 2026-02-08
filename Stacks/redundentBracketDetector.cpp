#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool check(stack<char> &st,char ch){
    
    if(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/'){
        while(st.top()!='('){
            st.pop();
        }
        st.pop();
        return false;
    }
    else{
        return true;
    }


}
bool detector(string &s){
    stack<char> st;
    for(auto it :s){
        if(it=='('||it=='+'||it=='-'||it=='*'||it=='/'){
            st.push(it);
        }
        else if(it==')'){
            
            if(check(st,it)){
                return false;
            }
            
        }
    }
    return true;-
}
int main(){

}