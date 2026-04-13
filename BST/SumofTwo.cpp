// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.


#include<iostream>
#include<vector>
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
void Inorder(Node* root,vector<int> & v){
    if(root==NULL) return;
    //l
    Inorder(root->left,v);
    v.push_back(root->data);
    Inorder(root->right);
}
bool SumofTwo(Node* root,int k){
    vector<int> v;
    Inorder(root,v);
    int i=0,j=v.size()-1;
    int sum;
    while(i<j){
        sum=v[i]+v[j];
        if(sum==k){
            return true;
        }
        if(sum>k){
            j--;
        }
        if(sum<k){
            i++;
        }
    }
}