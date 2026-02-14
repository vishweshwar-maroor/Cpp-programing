#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    // constructor
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
node* buildTree(node *root)
{
    cout << "Enter data :" << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);

    cout << "Insert data for left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Insert data for right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTraversal(node *root)
{
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data;
            if(temp->left!=nullptr){
                q.push(temp->left);
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
            }
        }
    }

}
int main()
{
    node *head;
    buildTree(head);
    // 1 2 5 -1 -1 6 -1 -1 3 7 -1 -1 8 -1 -1
    cout << "level order traversal" << endl;

    levelOrderTraversal(head);
}