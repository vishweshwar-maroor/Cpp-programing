#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
bool isIdentical(Node* r1, Node* r2) {
        // code here
        if(r1==NULL &&r2==NULL) return true;
        if(r1==NULL &&r2!=NULL) return false;
        if(r1!=NULL &&r2==NULL) return false;
        
        if(r1->data!=r2->data){
            return false;
        }
        else{
            return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
        }
    }
int main(){}