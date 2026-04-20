#include <iostream>
#include <vector>
/*Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
        return;
    // l
    inorder(root->left, v);
    v.push_back(root->val);
    // r
    inorder(root->right, v);
}
TreeNode* formBST(vector<int>& v, int start, int end) {
        // basecase
        if (start > end) {
            return NULL;
        }
        int mid = start+(end-start)/2 ;
        TreeNode* root = new TreeNode(v[mid]);

        root->left = formBST(v, start, mid-1);
        root->right = formBST(v, mid+1 , end);
        return root;
    }
TreeNode *balanceBST(TreeNode *root)
{
    vector<int> v;
    inorder(root, v);
    TreeNode *rootnew == NULL;

    formBST(newroot, v, 0, v.size() - 1);
    return rootnew;
}
