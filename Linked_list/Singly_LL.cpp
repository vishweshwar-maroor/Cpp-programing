#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void InsertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void InsertAtHead(node *&head, int d)
{   if(head==NULL){
    head=new node(d);
    return;
}
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
void printLL(node *&Head)
{
    node *thead = Head;
    while (thead != NULL)
    {
        cout << thead->data << " ";
        thead = thead->next;
    }
}
void InsertInBetween(node *&head, int position, int d)
{
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    } 

    node *thead = head;
    for (int i = 1; i <= position - 1; i++)
    {
        if (thead->next == NULL)
        {
            cout << "Length of Linked exeded hence data is apended at last" << endl;
            InsertAtTail(thead, d);
            return;
        }
        thead = thead->next;
    }
    node *temp = new node(d);
    temp->next = thead->next;
    thead->next = temp;
}
void deleteFront( node* &head){
    node* dhead=head;
    head=head->next;
    delete dhead;
    dhead=NULL;
}
void deleteBack(node* &head,node* &tail){
    if(head->next==NULL||head==tail){
        delete head;
        head==NULL;
        tail==NULL;
    }
    node* dhead=head;
    while(dhead->next->next!=NULL){
        dhead=dhead->next;
    }
    tail=dhead;
    dhead=dhead->next;
    delete dhead;
    dhead=NULL;

}
void deleteAtPosition(node* &head,int position){
    if(position==1){
        deleteFront(head);
        return;
    }
    
    node* dhead=head;
    for(int i=2;i<position;i++){
        if(i<position-1&& dhead->next==NULL){
            cout<<"Unable to delete as length of linked list is "<<i<<endl;
            return;
        }
        dhead=dhead->next;
    }
    node* nodeToDelete=dhead->next;
    dhead->next=dhead->next->next;
    delete nodeToDelete;
    dhead=NULL;
    dhead=NULL;
    return;


}



