/*You are given n BST (binary search tree) root nodes for n separate BSTs stored in an array trees (0-indexed). Each BST in trees has at most 3 nodes, and no two roots have the same value. In one operation, you can:

Select two distinct indices i and j such that the value stored at one of the leaves of trees[i] is equal to the root value of trees[j].
Replace the leaf node in trees[i] with trees[j].
Remove trees[j] from trees.
Return the root of the resulting BST if it is possible to form a valid BST after performing n - 1 operations, or null if it is impossible to create a valid BST.

A BST (binary search tree) is a binary tree where each node satisfies the following property:

Every node in the node's left subtree has a value strictly less than the node's value.
Every node in the node's right subtree has a value strictly greater than the node's value.
A leaf is a node that has no children.*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
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
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}
//duplicate remover
void duplicateRemove(vector<int> &v){
    // v is sorted array
    v.erase(std::unique(v.begin(), v.end()), v.end());
}
TreeNode *formBST(vector<int> &v, int start, int end)
{
    // basecase
    if (start > end)
    {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(v[mid]);

    root->left = formBST(v, start, mid - 1);
    root->right = formBST(v, mid + 1, end);
    return root;
}

TreeNode *canMerge(vector<TreeNode *> &trees)
{
    // inorder
    vector<int> data;
    for (auto i : trees)
    {
        inorder(i, data);
    }
    // sorting

    sort(data.begin(), data.end());
    //deleting duplicates
    data.erase(std::unique(data.begin(),data.end(),data.end())); 
    return formBST(data, 0, data.size() - 1);
}
int main() {}