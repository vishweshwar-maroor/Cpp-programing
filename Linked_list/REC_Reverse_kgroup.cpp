#include<iostream>
#include"C:\Users\Vishweshwar Maroor\Desktop\C ++ Programing\Linked_list\Singly_LL.cpp"
using namespace std;
node* kreverse(node* &head,int k){
    if(head==NULL){
        return NULL;
    }
    // reverse
    node *prev=NULL,*curr=head,*forw=head->next;
    for(int i=0;i<k;i++){
        if(curr==NULL){
            return prev;
            curr->next=prev;
            prev=curr;
            curr=forw;
            forw=forw->next;
        }
    }
    head=kreverse(prev,k);
    return prev;
}


node* reverse(node*prev,node* curr,node*forw,int k){
    if(forw==NULL){
        curr=prev;
        return curr;

    }
    node* temphead=curr;
    for(int i=0;i<k;i++){
        if(forw==NULL){
            break;
        }
        curr->next=prev;
        prev=curr;curr=forw;
    }
    curr->next=prev;
    temphead->next=reverse(NULL,forw,forw->next,k);
    return curr;


}
node* RecReverse(node* &head,int k){
    
    if(k==1||k==0){
        return head;
    }
    //iterative 
    node* prev=NULL;
    node* curr=head;
    node* forw=head->next;
    for(int i=0;i<k;i++){
        if(forw==NULL){
            break;
        }
        curr->next=prev;
        prev=curr;curr=forw;
        forw=forw->next;
    }
    if(forw==NULL){
        curr->next=prev;
        return curr;
    }
    
    head->next=RecReverse(curr,k);
    return prev;

    

}

int main(){
    node* head=new node(10);
    node* tail=head;
    InsertAtTail(tail,20);
    InsertAtTail(tail,30);
    InsertAtTail(tail,40);
    InsertAtTail(tail,50);
    InsertAtTail(tail,60);
    InsertAtTail(tail,70);
    InsertAtTail(tail,80);
    InsertAtTail(tail,90);
    InsertAtTail(tail,100);
    for(int i=110;i<=300;i=i+10){
        InsertAtTail(tail,i);

    }

    head=RecReverse(head,2);
    printLL(head);

}