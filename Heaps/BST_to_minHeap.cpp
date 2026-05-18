/*
Given a binary search tree which is also a complete binary tree. The problem is
to convert the given BST into a Min Heap with the condition that all the values
in the left subtree of a node should be less than all the values in the right
subtree of the node. This condition is applied to all the nodes, in the
resultant converted Min Heap. approch Create an array arr of size n, where n is
the number of nodes in the given BST. Perform the inorder traversal of the BST
and copy the node values in the arr[] in sorted order. Now perform the preorder
traversal of the tree. While traversing the root during the preorder traversal,
one by one copy the values from the array arr[] to the nodes of the BST.
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node {
 private:
 public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    left = right = NULL;
    data = val;
  };
};
class Solution {
 private:
 void inorder(Node* &root,vector<int> &arr){
    if(root==NULL) return ;
    //l
    inorder(root->left,arr);
    //n
    arr.push_back(root->data);
    //r
    inorder(root->right,arr);

 }
 void preorder(Node* &root,vector<int> &arr,int &i){
    if(root==NULL) return;
    root->data=arr[i];
    i++;
    preorder(root->left,arr,i);
    preorder(root->right,arr,i);
 }
 public:
  void BSTtoheap(Node*& root) {
    vector<int> arr;
    inorder(root,arr);
    preorder(root,arr,0)

  }
};