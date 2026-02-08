#include<iostream>
#include"C:\Users\Vishweshwar Maroor\Desktop\C ++ Programing\Linked_list\Singly_LL.cpp"
using namespace std;
void sort(node* &head){
    node* head0=NULL,*tail0=NULL;
    node* head1=NULL,*tail1=NULL;
    node* head2=NULL,*tail2=NULL;
    int count0=0,count1=0,count2=0;

    node* thead=head;
    while(thead!=NULL){
        if(thead->data==0){
            InsertAtHead(head0,0);
            
            if(count0==0){
                tail0=head0;
                count0++;
            }
            thead=thead->next;
        }
        else if(thead->data==1){
            InsertAtHead(head1,1);
            if(count1==0){
                tail1=head1;
                count1++;
            }
            thead=thead->next;
        }
        else if(thead->data==2){
            InsertAtHead(head2,2);
            if(count2==0){
                tail2=head2;
                count2++;
            }
            thead=thead->next;
        }
    }
    
    tail0->next=head1;
    tail1->next=head2;
    tail2->next=NULL;
    thead=head;
    head=head0;
    node* t2head=thead->next;
    while(t2head!=NULL){
        delete thead;
        thead=t2head;
        t2head=t2head->next;
    }


}


int main(){
    node* head=new node(0);
    node* tail=head;
    InsertAtTail(tail,2);
    InsertAtTail(tail,1);
    InsertAtTail(tail,1);
    InsertAtTail(tail,0);
    sort(head);
    printLL(head);

}