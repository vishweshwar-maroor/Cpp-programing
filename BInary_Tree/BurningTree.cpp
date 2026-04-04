#include<iostream>
#include<queue>
#include<map>
using namespace std;
class Node{
    public:
    int data;
    Node* left , *right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
void nodeToParent(Node* root,map<Node*,Node*> &nodetoParent){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    nodetoParent[root]=NULL;
    while(!q.empty()){
        Node* current=q.front();
        q.pop();
        if(current->left){
            nodetoParent[current->left]=current;
            q.push(current->left);
        }
        if(current->right){
            nodetoParent[current->right]=current;
            q.push(current->right);
        }
    }
}
Node* findNode(Node* root,int target){
    if(root==NULL) return NULL;
    if(root->data==target){
        return root;
    }
    Node* left=findNode(root->left,target);
    if(left!=NULL) return left;
    return findNode(root->right,target);
}
void caltime(Node* target,map<Node*,bool> &visited,int &time,map<Node*,Node*> &nodetoParent){
    if(target==NULL) return;
    queue<Node*> q;
    q.push(target);
    visited[target]=true;
    while(!q.empty()){
        int levelSize=q.size();
        bool burned=false;
        
        for(int i=0;i<levelSize;i++){
            Node* current=q.front();
            q.pop();
            if(current->left && !visited[current->left]){
                visited[current->left]=true;
                q.push(current->left);
                burned=true;
            }
            if(current->right && !visited[current->right]){
                visited[current->right]=true;
                q.push(current->right);
                burned=true;
            }
            Node* parent=nodetoParent[current];
            if(parent && !visited[parent]){
                visited[parent]=true;
                q.push(parent);
                burned=true;
            }
        }
        if(burned) time++;
    }
}
int minTime(Node* root, int target){
    if(root==NULL) return 0;
    map<Node*,Node*> nodetoParent;
    nodeToParent(root,nodetoParent);
    Node* targetPos=findNode(root,target);
    if(targetPos==NULL) return 0;
    map<Node*,bool> visited;
    int time=0;
    caltime(targetPos,visited,time,nodetoParent);
    return time;
}
int main(){}
