// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
  
// Comoplexity time O(N)
// space O(h)

#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* LCA(Node* root,Node* n1,Node* n2){
    // Basecase
    if(root==NULL) return NULL;
    //root matches nodes it is lca
    if(root==n1 || root==n2) return root;
    Node* leftlca=LCA(root->left,n1,n2);
    Node* rightlca=LCA(root->right,n1,n2);

    //Check if both are ot NULL
    //IF both are not NULLthe root is lca
    if(leftlca && rightlca) return root;

    //IF no
    return (leftlca? leftlca:rightlca);


}
int main()