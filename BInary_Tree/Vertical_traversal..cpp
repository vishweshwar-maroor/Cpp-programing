/*For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.*/
#include <iostream>
// #include<bits/stdc++.h>
#include <queue>
#include <vector>
#include <map>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
vector<vector<int>> verticalOrder(Node *root)
{
    // code here
    map<int, map<int, vector<int>>> nodes;
    vector<vector<int>> ans;
    queue<pair<Node *, pair<int, int>>> q; // Node* hd,lvl
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        int lvl = temp.second.second;
        int hd = temp.second.first;
        Node *node = temp.first;
        nodes[hd][lvl].push_back(node->data);
        if (node->left)
        {
            q.push(make_pair(root->left, make_pair(hd - 1, lvl + 1)));
        }
        if (node->right)
        {
            q.push(make_pair(root->right, make_pair(hd + 1, lvl + 1)));
        }
    }
    for(auto i: nodes){
        
        for(auto j: i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
        
    }
    return ans;
}

int main() {}