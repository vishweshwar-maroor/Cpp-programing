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
    nodetoParent.insert({root->left,root});
    nodetoParent.insert({root->right,root});
    nodeToParent(root->left,nodetoParent);
    nodeToParent(root->right,nodetoParent);
    
}
Node* findNode(Node* root,int target){
    if(root->data==target){
        return root;
    }
    if(root==NULL) return NULL;
    Node* left=findNode(root->left,target);
    Node* right=findNode(root->right,target);
    if(left!=NULL) return left;
    else if(right!=NULL) return right;
    else {
        return NULL;
    }


}
void caltime(Node* &target,map<Node*,bool> &visited,int &time,map<Node*,Node*> &nodetoParent){
    queue<Node*> q;
    q.push(target);
    visited[target]=true;
    
    while(!q.empty()){
        int initialzSize=q.size();
        if(target->left!=NULL&&visited[target->left]!=true){
            q.push(target->left);
            visited[target->left]=true;
        }
        if(target->right!=NULL&&visited[target->right]!=true){
            q.push(target->right);
            visited[target->right]=true;
            
        }
        if(nodetoParent[target]!=NULL&&visited[nodetoParent[target]]!=true){
            q.push(nodetoParent[target]);
            visited[nodetoParent[target]]=true;
        }
        int finalSize=q.size();
        if(finalSize!=initialzSize) time++;
        
    }
}
int minTime(Node* root, int target){
    //mapping parent to node
    map<Node*,Node*> nodetoParent;
    nodetoParent.insert({NULL,root});
    nodeToParent(root,nodetoParent);
    //firn traget node
    Node* targetPos=findNode(root,target);

    //calculating time
    map<Node*,bool> visited;
    queue<Node*> q;
    int time=0;
    caltime(targetPos,visited,time,nodetoParent);
    return time;


}
int main(){}