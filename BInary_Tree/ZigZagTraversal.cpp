#include<iostream>
#include<queue>
#include<staack>

using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void ZigzagTraversal(node* root){
    queue<node*> q;
    q.push(root);
    bool flag=true;
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(flag==true){
            cout<<temp->data;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            flag=!flag;
        }
        else{
            cout<<temp->data;
            if(temp->right) q.push(temp->right);
            if(temp->left) q.push(temp->left);
            flag=!flag;
        }
    }
}