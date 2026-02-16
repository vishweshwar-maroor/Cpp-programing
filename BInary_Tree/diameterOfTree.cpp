#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
int heightOfTree(node *root)
{
    // basecase
    if (root == NULL)
    {
        return 0;
    }
    int x = heightOfTree(root->left);
    int y = heightOfTree(root->right);
    int h = max(x, y);
    return h + 1;
}

//optimized code
pair<int, int> diafast(TreeNode* root) {
        if (root == NULL) {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        pair<int, int> left = diafast(root->left);
        pair<int, int> right = diafast(root->right);
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int, int> ans = make_pair(max(op1, max(op2, op3)),
                                       max(left.second, right.second) + 1);
        return ans;
    }

int diameterOfBinaryTree(node *root)
{
    // Write Your Code Here.
    if (root == NULL)
    {
        return 0;
    }
    int op1 = diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    int op3 = (heightOfTree(root->left) + heightof(root->right) + 1);
    int maxi = max(op1, op2);
    return max(maxi, op3) - 1;
}
int main()
{
}