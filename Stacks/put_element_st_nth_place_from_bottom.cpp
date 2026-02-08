#include<iostream>
#include<stack>
using namespace std;
//recursively
void nthplace(stack<int> &st,int data,int place){
    // basecase
    if(st.size()==place){
        st.push(data);
        return;
    }
    int x= st.top();
    st.pop();
    nthplace(st,data,place);
    st.push(x);
}