#include<iostream>
#include<stack>
using namespace std;
void atend(stack<int>& st,int data){
    //basecase
    if(st.size()==0){
        st.push(data);
        return;
    }
    int x=st.top();
    st.pop();
    atend(st,data);
    st.push(x);

}
void reverse(stack<int> & st){
    //basecase
    if(st.size()==0){
        return;
    }
    int x=st.top();
    st.pop();
    reverse(st);
    atend(st,x);
    
}
void print(stack<int> &st)
{
    while (st.size() > 0)
    {
        cout << st.top();
        st.pop();
    }
}
int main()
{
    stack<int> st;
    
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    
    reverse(st);
    print(st);
}