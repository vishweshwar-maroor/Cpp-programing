#include<iostream>
#include<stack>
using namespace std;
bool match(char top,char str){
    if(top=='('&& str==')'){
        return 1;
    }
    else if(top=='['&& str==']'){
        return 1;
    }
    else if(top=='{'&& str=='}'){
        return 1;
    }
    else{return 0}
}
string isValidParenthesis(string &str){
    stack<char> st;
    for(int i=0;i<str.size();i++){
        if(str[i]==')'||str[i]==']'||str[i]=='}'){
            if(match(st.top(),str[i])){
                st.pop();
            }
            else{
                return "Unvalid"
            }
        }
        if else{str[i]=='('||str[i]=='['||str[i]=='{'}{
            st.push(str[i]);
        }
        else{
            return "invalid characters"
        }
        if(st.size()==0){
            return "valid parenthesis"
        }
        else{
            return "Unvalid"
        }
    }
}
int main(){
    string str;
    string str2=isValidParenthesis(str);
}