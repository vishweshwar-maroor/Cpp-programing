#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Node{
    public:
    int data;
    Node* left, *right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
void maping(map<int,vector<int>::iterator> mp,vector<int>::iterator li,vector<int>::iterator ri){
    while(li<=ri){
        mp.insert({*li,li});
        li++;
    }
}
Node* build(vector<int>::iterator li,vector<int>::iterator ri,vector<int>::iterator lp,vector<int>::iterator rp){
    if(ri-li<=1){
        Node* temp=new Node(*li);
        return temp;
    }
    map<int,vector<int>::iterator> mp;
    maping(mp,li,ri);
    vector<int>::iterator node=mp[lp];
    Node* root=new Node(*lp);
    int left_size = node-li;
    root->left = build(li, node, lp + 1, lp + 1 + left_size);
    root->right = build(node + 1, ri, lp + 1 + left_size, rp);
    return root;
}
Node* BinaryTree(vector<int>& inorder,vector<int>& preorder){
    Node* root=build(inorder.begin(),inorder.end(),preorder.begin(),preorder.end())
    return root;
}
int main(){}