#include<iostream>
#include "C:\Users\Vishweshwar Maroor\Desktop\C ++ Programing\Linked_list\Singly_LL.cpp"
using namespace std;
node* reverse1(node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node* chottahead=reverse1(head->next);
    head->next->next=head;
    head->next=NULL;
    return chottahead;
}
void reverseBacktrack(node* &head){
    
    head=reverse1(head);
    
}
void ReverseLL(node* &head){
    node* prev= NULL;
    node* curr=head;
    node* forw=head->next;
    while(forw!=NULL){
        curr->next=prev;
        prev=curr;
        curr=forw;
        forw=forw->next;

    }
    curr->next=prev;
    head=curr;
}



int main(){
    node* head=new node(10);
    node* tail=head;
    InsertAtTail(tail,20);
    InsertAtTail(tail,30);
    InsertAtTail(tail,40);
    InsertAtTail(tail,50);
    
    
    // printLL(head);
    // ReverseLL(head);
    // cout<<endl;
    // printLL(head);
    reverseBacktrack(head);
    printLL(head);



}