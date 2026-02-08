#include<iostream>
using  namespace std;
class Stacks {
    private:
    //properties
    int size;
    int top;
    int* arr;
    public:
    Stacks(int size){
        this->size=size;
        top=-1;
        arr= new int[size];
    }
    
    void push(int value){
        if(top>=size-1){
            cout<< "stack overflow";
        }
        else{
            top++;
            arr[top]=value;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack underflow";
        }
    }
    int peek(){
        if(top>=0){
            cout<<arr[top];
            return arr[top];
        }
        else{
            cout<<"stack empty";
        }
    }
    int length(){
        return top+1;
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    int capacity(){
        return size;
    }
};
int main(){
    Stacks st(10);
    st.push(5);
    st.peek();
    st.push(4);
    st.peek();
    st.push(3);
    st.peek();
    st.push(2);
    st.peek();
    

}