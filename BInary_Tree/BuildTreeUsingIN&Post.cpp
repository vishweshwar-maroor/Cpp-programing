#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
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
map<int ,int> valToIndex(vector<int> &inorder){
    map<int ,int> mp;
    for(int i=0;i<inorder.size();i++){
        mp.insert({inorder[i],i});
    }
    return mp;
}
Node* build(vector<int> &inorder,vector<int> & postorder,int inl,int inr,int pol,int por,map<int ,int> &mp){
    if(inl>=inr||pol>=por){
        return NULL;
    }
    Node* root=new Node(postorder[por]);
    int pos=mp.at(postorder[por]);
    root->left=build(inorder,postorder,0,  ,0,postorder.size()-1,mp)

}
Node* BuildTree(vector<int> &inorder,vector<int> & postorder){
    map<int ,int> mp=valToIndex(inorder);
    return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,mp)
}
int main(){}