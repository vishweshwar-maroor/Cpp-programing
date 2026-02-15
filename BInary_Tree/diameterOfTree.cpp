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
}
int diameterOfBinaryTree(node *root){
	// Write Your Code Here.
    if(root==NULL){
        return 0;
    }
    int op1=diameterOfBinaryTree(root->left);
    int op2=diameterOfBinaryTree(root->right);
    int op3=(height(root->left)+height(root->right)+1);
    int maxi=max(op1,op2);
    return max(maxi,op3)-1;
}
int main(){

}