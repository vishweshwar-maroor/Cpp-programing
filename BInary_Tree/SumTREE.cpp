/*
Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false.

A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.
*/
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};
pair<int ,bool> sum(Node* root){
        if(root==NULL) {
            return {0,true};
        }
        if(root->left==NULL&&root->right==NULL){
            return {root->data,true};
        }
        pair<int ,bool> p1=sum(root->left);
        pair<int ,bool> p2=sum(root->right);
        pair<int ,bool> p3={p1.first+p2.first,p1.second&&p2.second};
        if(p3.second==false){
            return {p3.first+root->data,false};
            
        }
        else{
            if(p3.first==root->data){
                return {p3.first+root->data,true};
            }
            else{
                return {p3.first+root->data,false};
            }    
        }
        
        
    }
    bool isSumTree(Node* root) {
        // Your code here
        pair<int,bool> p=sum(root);
        return p.second;
    }