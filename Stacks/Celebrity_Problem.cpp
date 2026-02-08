/*Problem statement
There are ‘N’ people at a party. Each person has been assigned a unique id between 0 to 'N' - 1(both inclusive). A celebrity is a person who is known to everyone but does not know anyone at the party.

Given a helper function ‘knows(A, B)’, It will returns "true" if the person having id ‘A’ know the person having id ‘B’ in the party, "false" otherwise. Your task is to find out the celebrity at the party. Print the id of the celebrity, if there is no celebrity at the party then print -1.

Note:
1. The helper function ‘knows’ is already implemented for you.
2. ‘knows(A, B)’ returns "false", if A doesn't know B.
3. You should not implement helper function ‘knows’, or speculate about its implementation.
4. You should minimize the number of calls to function ‘knows(A, B)’.
5. There are at least 2 people at the party.
6. At most one celebrity will exist.*/

#include <bits/stdc++.h> 
bool knows(int A,int B){
    
}
using namespace std;
int celebrity(int n){
    stack<int> st;
    int A,B;
    for(int i=0;i<n;i++){
        st.push(i);
    }
    
    while(st.size()!=1){
        A=st.top();
        st.pop();
        B=st.top();
        st.pop();
        if(!knows(A,B)){
            st.push(A);
        }
        if(!knows(B,A)){
            st.push(B);
        }

    }
    A=st.top();
    //check
    int Z=1;
    for(int i=0;i<n;i++){
        if(n==A){
            continue;
        }
        if(knows(A,i)){
            Z=0;
            break;
        }
        if(!knows(i,A)){
            Z=0;
            break;
        }
    }
    if(Z==1){
        return A;
    }
    else{
        return -1;
    }

}
int main(){

}