#include<iostream>
#include<map>

#include"C:\Users\Vishweshwar Maroor\Desktop\C ++ Programing\Linked_list\Singly_LL.cpp"
using namespace std;
void deleter(node* &head,node* &tail){
    node* temp=tail;
    while(head->data==head->next->data){
        deleteAtPosition(head,2);
    }
    return;

}
void mapDelete(node* &head){
     if(head==NULL||head->next==NULL){
        return;
    }
    node* prev=head;
    node* curr=head->next;
    map<int,int> m;
    node* temp;
    m.insert({head->data,1});
    while(curr!=NULL){
        
        if(m[curr->data]==1){
            if(curr->next==NULL){
                delete curr;
                prev->next=NULL;
                curr=NULL;
            }
            temp=curr;
            curr=curr->next;
            prev->next=curr;
            delete temp;
        }
        else{
            m.insert({curr->data,1});
            for(auto it=m.begin();it!=m.end();++it){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;
            curr=curr->next;
            prev=prev->next;
            
        }
    }
    for(auto it=m.begin();it!=m.end();++it){
        cout<<it->first<<" "<<it->second<<endl;
    }
}


void DeleteDuplicate(node* &head){
    if(head==NULL||head->next==NULL){
        return;
    }
    node* head1=head;
    node* head2=head->next;
    while(head2!=NULL){
        if(head1->data==head2->data){
            head1->next=head1->next->next;
            delete head2;
            head2=head1->next;
        }
        else{
        head1=head1->next;
        head2=head2->next;
        }
        
        

    }
    
    return;
}

int main(){
    node* head=new node(10);
    node* tail=head;
    InsertAtTail(tail,10);
    InsertAtTail(tail,20);
    InsertAtTail(tail,20);
    InsertAtTail(tail,30);
    InsertAtTail(tail,30);
    InsertAtTail(tail,30);
    InsertAtTail(tail,40);
    InsertAtTail(tail,40);
    InsertAtTail(tail,50);
    InsertAtTail(tail,50);
    InsertAtTail(tail,50);
    InsertAtTail(tail,60);
    //printLL(head);
    cout<<endl;
    mapDelete(head);
    printLL(head);

}
