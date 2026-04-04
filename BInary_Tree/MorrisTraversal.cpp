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

vector<int> MorrisTraversal(Node* root){
    Node* curr=root;
    vector<int> ans;
    while(curr!=NULL){
        if(root->left!=NULL){
            ans.push_back(curr->data);
            curr=curr->right;
        }
        else{
            Node* pre=curr->left;
            while(pre->right!=NULL&&pre->right!=curr){
                pre=pre->right;
            }
            if(pre->right==NULL){
                pre->right=curr;
                curr=curr->left;
            }
            else{
                pre->right=NULL;
                ans.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
}