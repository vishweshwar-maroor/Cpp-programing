#include<iostream>
using namespace std;
class node{
    public:
    node* next;
    
    int data;
    
    node(int x){
        this->data=x;
        next=NULL;
        
    }

};
class Stack{
    private:
    node* head;
    int size=0;
    public:
    Stack(){
        head=NULL;
    }
    Stack(int x){
        head= new node(x);
        size++;
    }
    void push(int x){
        if(head==NULL){
            node* temp= new node(x);
            
            head=temp;
            size++;
        }
        else{
            node* temp= new node(x);
            temp->next=head;
            head=temp;
            size++;
        }
    }
    void pop(){
        if(head==NULL){
            cout<<"stack underflow";
        }
        else{
            node* temp= head;
            head=head->next;
            
            delete temp;
            size--;
        }
    }
    int length(){
        return size;
    }
    int peek(){
        return head->data;
    }
    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }


};
int main(){
    Stack st;
    st.push(5);
    st.push(6);

    cout<<st.peek();
    
}