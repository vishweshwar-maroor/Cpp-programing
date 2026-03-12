#include <iostream>
#include <cmath>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}
bool isBalanced(Node* root) {
    if (root == NULL) {
        return true;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    
    root->left->left = new Node(4);
    
    if (isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
    return 0;
}
