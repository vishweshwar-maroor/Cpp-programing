// You are given the root of a Binary Search Tree (BST), your task is to flatten the tree such that the left child of every node points to NULL, and the right child points to the next node in the sorted order of the BST

#include<iostream>
class Solution {
    
  public:
  void nodegenerate(int data,Node* &newroot,Node* &tail){
      if(newroot==NULL){
          newroot=new Node(data);
          tail=newroot;
      }
      else{
          tail-> right=new Node(data);
          tail=tail->right;
      }
  }
  void Inorder(Node* root,Node* &newroot,Node* &tail){
      if(root==NULL) return;
      Inorder(root->left,newroot,tail);
      nodegenerate(root->data,newroot,tail);
      Inorder(root->right,newroot,tail);
  }
    Node *flattenBST(Node *root) {
        // code here
        Node* newroot=NULL;
    Node* tail=NULL;
        Inorder(root,newroot,tail);
        return newroot;
    }
};