#include <iostream>
#include <stack>
using namespace std;
void deleteMiddle(stack<int> &st)
{
    int size = st.size();
    stack<int> st2;
    
        for (int i = 0; i < size / 2; i++)
        {
            st2.push(st.top());
            st.pop();
        }
    
       
    
    st.pop();
    while (st2.size() > 0)
    {
        st.push(st2.top());
        st2.pop();
    }
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
    deleteMiddle(st);
    print(st);
}