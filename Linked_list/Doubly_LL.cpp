#include<iostream>
#include<map>
using namespace std;
class node{
    public:
    node* previous;
    node* next;
    int data;
    node(int d){
        this->data=d;
        this->next=NULL;
        this->previous=NULL;
    }
};
void insertAtHead(node* &head,int d){
    node* temp=new node(d);
    temp->next=head;
    head->previous=temp;
    head=temp;
    temp=NULL;
    return;
}
void insertAtTail(node* &tail,int d){
    node* temp=new node(d);
    tail->next=temp;
    temp->previous=tail;
    tail=temp;
    temp=NULL;
    return;

}
void insertAtPosition(node* &head,int position,int d){
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    node* thead1=head;
    node* thead2=head->next;
    for(int i=2;i<position;i++){
        if(i<position-1&& thead2->next==NULL){
            cout<<"length of Linkedlist is "<<i+1<<" length exeded hence data not added"<<endl;
            return;
        }
        thead1=thead1->next;
        thead2=thead2->next;

    }
    node* temp =new node(d);
    temp->next=thead2;
    thead2->previous=temp;
    temp->previous=thead1;
    thead1->next=temp;
    thead1=NULL;
    thead2=NULL;
    temp=NULL;
    return;

}
int getLength(node* &head){
    node* thead=head;
    int count=1;
    while(1){
        if(thead->next==NULL){
            count++;
            break;
        }
        count++;
    }
    return count;
}
void deleteAtHead(node* &head){
    node* dhead=head;
    head=head->next;
    head->previous=NULL;
    delete dhead;
    dhead=NULL;
    return;
}
void deleteAtTail(node* &tail){
    node* dtail=tail;
    tail=tail->previous;
    tail->next=NULL;
    delete dtail;
    dtail=NULL;
}
void deleteAtPosition(node* &head,int position){
    if(position==1){
        deleteAtHead(head);
        return;
    }
    node* dhead=head;
    for(int i=1;i<=position;i++){
        
        if(i<position && dhead->next==NULL ){
            cout<<"Length of LL is shorter than the position"<<endl;
        }
        return;
        dhead=dhead->next;
    }
    dhead->previous->next=dhead->next;
    dhead->next->previous=dhead->previous;
    delete dhead;
    dhead=NULL;
    return;
    

}

int main(){
    map<int,bool>

}