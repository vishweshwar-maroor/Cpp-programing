#include <iostream>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
    node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
node *buildTree(node *root)
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
void buildtree(node* root){
    //basecats
}

void inOrder(node *root)
{
    // basecase
    // LNR
    if (root == nullptr)
        return;

    // L
    inOrder(root->left);
    // N
    cout << root->data << " ";
    // R
    inOrder(root->right);
}
void preOrder(node *root){
    //basecase
    if(root==nullptr) return;
    //N
    cout<<root->data<<" ";
    //L
    preOrder(root->left);
    //R
    preOrder(root->right);               
}
void postOrder(node *root){
    //basecase
    if(root==nullptr) return;

     //L
    postOrder(root->left);
    //R
    postOrder(root->right);
    //N
    cout<<root->data<<" ";
   
}
void buildfromLevelOrder(node *root){
    queue<node*> q;
    cout<<"enter data for root";
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        cout<<"enter data for left node of :"<<temp->data<<endl;
        cin>>data;
        if(data!=-1){
            temp->left=new node(data);
            q.push((temp->left));
        }
        cout<<"enter data for right node of :"<<temp->data<<endl;
        cin>>data;
        if(data!=-1){
            temp->right=new node(data);
            q.push((temp->right));
        }
    }

}
int main()
{
    node *head = NULL;
    // head = buildTree(head);
    // // 1 2 5 -1 -1 6 -1 -1 3 7 -1 -1 8 -1 -1
    // cout << "level order traversal" << endl;

    // //inOrder(head);
    // postOrder(head);
    buildfromLevelOrder(head);
    return 0;
}