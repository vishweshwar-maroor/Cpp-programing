#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int> &st,int x){
    //basecase
    if(st.empty()){
        st.push(x);
        return;
    }
    if(x<st.top()){
        st.push(x);
        return;
    }
    int y=st.top();
    st.pop();
    solve(st,x);
    st.push(y);
}
void sort(stack<int> &st){
    //basecase
    if(st.empty()){
        return;
    }
    int x=st.top();
    st.pop();
    sort(st);
    solve(st,x);
}
void print(stack<int> &st)
{
    while (st.size() > 0)
    {
        cout << st.top()<<" ";
        st.pop();
    }
}
int main()
{
    stack<int> st;
    int x;
    for(int i=0;i<5;i++){
        cin>>x;
        st.push(x);
    }
    
    sort(st);
    print(st);
}