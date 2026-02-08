#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    

class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
Node* cloneLinkedList(Node* head) {
        // code here
        Node* temp= head;
        Node* clonetemp=new Node(head->data);
        Node* clone=clonetemp; 
        
        unordered_map<Node*,Node*> hash;


        while(clonetemp!=NULL){
            InsertAtTail(clonetemp,temp->data);
            hashmap.insert({clonetemp,temp});
            hashmap.insert({temp,clonetemp});
            clonetemp=clonetemp->next;
            temp=temp->next;
        }
        clonetemp=clone;
        temp=clone;
        while(clonetemp!=NULL){
            temp=hashmap.at(clonetemp);
            temp=temp->random;
            temp=hashmap.at(temp);
            clonetemp->random=temp;
            clonetemp=clonetemp->next;
            temp=clonetemp;

        }

        return clone;

        
    }
int main(){

}    