class Solution
{
public:
    Node *search(Node *root, int key)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (root->data < key)
        {
            return search(root->right, key);
        }
        else
        {
            return search(root->left, key);
        }
        Node *predessor(Node * root)
        {
            while (root->right != NULL)
            {
                root = root->right;
            }
            return root;
        }
        Node *successor(Node * root)
        {
            while (root->left != NULL)
            {
                root = root->left;
            }
            return root;
        }
    }
    vector<Node *> findPreSuc(Node *root, int key)
    {
        // code here
        vector<Node *> ans;
        // predessor
        binaryTreeNode *target = search(root, key);
        Node *pre = predessor(target->left);
        Node *suc = successor(target->right);
        ans.push_back(pre);
        ans.push_back(suc);
        return ans;
    }
};