#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *left,*right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
int heightOfTree(node* root){
    //basecase
    if(root==NULL){
        return 0;
    }
    int x=heightOfTree(root->left);
    int y=heightOfTree(root->right);
    int h=max(x,y);
    return h+1;
}
int main(){

}