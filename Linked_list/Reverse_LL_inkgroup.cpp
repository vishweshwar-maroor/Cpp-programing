
#include<iostream>
#include"C:\Users\Vishweshwar Maroor\Desktop\C ++ Programing\Linked_list\Singly_LL.cpp"
using namespace std;

pair<node*,node*> reverse(node* &head,node* &tail){
    node* prev= NULL;
    node* curr=head;
    node* forw=head->next;
    while(forw!=tail){
        curr->next=prev;
        prev=curr;
        curr=forw;
        forw=forw->next;

    }
    curr->next=prev;
    forw->next=curr;
    
    return {tail,head};
}
void ReverseK(node* &head,int k){
    pair<node*,node*> p1={NULL,NULL};
    pair<node*,node*> p2={NULL,NULL};
    node* t1=head;
    node* t2=head;
    for(int i=0;i<k;i++){
        if(t2->next==NULL){
            break;
        }
        t2=t2->next;
    }
    while(t2->next!=NULL){
        t1=t2->next;
        for(int i=0;i<k;i++){
        if(t2->next==NULL){
            break;
        }
        t2=t2->next;
    }
    reverse(t1,t2);

    }
    reverse(t1,t2);
}
int main(){
    node* head=new node(10);
    node* tail=head;
    InsertAtTail(tail,20);
    InsertAtTail(tail,30);
    InsertAtTail(tail,40);
    InsertAtTail(tail,50);
    printLL(head);
    cout<<endl;
    ReverseK(head,2);
    printLL(head);

}