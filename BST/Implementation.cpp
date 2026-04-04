#include<iostream> 
using namespacestd;
class Node
{
private:
    
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        left=right=NULL;
        data=val;
    };
    ~Node();
};
//recursive
Node* InsertIntoBST(Node* &root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data>root->data){
        root->right=InsertIntoBST(root->right,data);
        
    }
    else{
        root->left=InsertIntoBST(root->left,data);
    }
    return root;
}
void ImplementBST(Node* &root,int data){
    Node* temp=root;
    if(root==NULL){
        root=new Node(data);
        return;
    }
    while(temp!=NULL){
        if(temp->data>data){
            if(temp->right==NULL){
                temp->right=new Node(data);
                return;
            }
            else{
                temp=temp->right;
            }
        }
        if(temp->data<data){
            if(temp->left==NULL){
                temp->left=new Node(data);
                return;
            }
            else{
                temp=temp->left;
            }
        }
    }
    return;
}
void takeInput(Node*& root){
    int x;
    cin>>x;
    while(x!=-1){
        ImplementBST(root,data);
        cin>>x;
    }
}

int main(){
    Node* root=NULL;
    cout<<"Enter data: ";
    takeInput(root);
}