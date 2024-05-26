#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    int height;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data = 0)
    {
        this->data = data;
        height = 1;
        left = NULL;
        right = NULL;
    }
};
class AVLTree
{
    TreeNode* root;
  public:
    AVLTree()
    {
        root = NULL;
    }
    TreeNode* leftRotate(TreeNode* x);
    TreeNode* rightRotate(TreeNode* node);
    TreeNode* insertWrapper(TreeNode* node, int key);
    void preOrderWrapper(TreeNode* node);
    void inOrderWrapper(TreeNode* node);
    bool search(int key);
    int balanceFactor(TreeNode* node);
    int getHeight(TreeNode* node);
    void insert(int key)
    {
        root = insertWrapper(root, key);
        cout<<"INSERTED KEY "<<key<<endl;
    }
    void preOrder()
    {
        cout<<"PREORDER: ";
        preOrderWrapper(root);
        cout<<endl;
    }
    void inOrder()
    {
        cout<<"INORDER: ";
        inOrderWrapper(root);
        cout<<endl;
    }
};
int AVLTree :: getHeight(TreeNode* node)
{
    if(!node)
        return 0;
    return node->height;
}
int AVLTree :: balanceFactor(TreeNode* node)
{
    if(node == NULL)
        return 0;
    int lh = 0;
    int rh = 0;
    if(node->left)
        lh = node->left->height;
    if(node->right)
        rh = node->right->height;
    return lh - rh;
}
TreeNode* AVLTree :: leftRotate(TreeNode* x)
{
    cout<<"Left Rotation Performed."<<endl;
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;
    x->right = T2;
    y->left = x;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}
TreeNode* AVLTree :: rightRotate(TreeNode* y)
{
    cout<<"Right Rotation Performed."<<endl;
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;
    y->left = T2;
    x->right = y;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}
TreeNode* AVLTree :: insertWrapper(TreeNode* node, int key)
{
    if(node == NULL)
        return new TreeNode(key);
    if(key < node->data)
        node->left = insertWrapper(node->left, key);
    else if(key > node->data)
        node->right = insertWrapper(node->right, key);
    else
    {
        cout<<"DUPLICATE INSERTION."<<endl;
        return node;
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = balanceFactor(node);
    if(bf>1 && key<node->left->data) // Left Left Insertion
    {
        cout<<"Left Left Insertion."<<endl;
        node = rightRotate(node);
    }
    else if(bf>1 && key>node->left->data) // Left Right Insertion
    {
        cout<<"Left Right Insertion."<<endl;
        node->left = leftRotate(node->left);
        node = rightRotate(node);
    }
    else if(bf<-1 && key>node->right->data) // Right Right Insertion
    {
        cout<<"Right Right Insertion."<<endl;
        node = leftRotate(node);
    } 
    else if(bf<-1 && key<node->right->data) // Right Left Insertion
    {
        cout<<"Right Left Insertion."<<endl;
        node->right = rightRotate(node->right);
        node = leftRotate(node);
    }
    else
    {
        return node;
    }
    return node;
}
bool AVLTree :: search(int key)
{
    TreeNode* curr = root;
    int comparisons = 0;
    while(curr)
    {
        comparisons++;
        if(curr->data == key)
        {
            cout<<"Comparisons: "<<comparisons<<endl;
            return true;
        }
        else if(curr->data < key)
            curr = curr->right;
        else
            curr = curr->left;
    }
    cout<<"Comparisons: "<<comparisons<<endl;
    return false;
} 
void AVLTree :: inOrderWrapper(TreeNode* node)
{
    if(!node)
        return;
    inOrderWrapper(node->left);
    cout<<node->data<<" ";
    inOrderWrapper(node->right);
}
void AVLTree :: preOrderWrapper(TreeNode* node)
{
    if(!node)
        return;
    cout<<node->data<<" ";
    preOrderWrapper(node->left);
    preOrderWrapper(node->right);
}
int main()
{
    AVLTree tree;
    int input[10] = {-15, 115, 16, 78, -785, -999, 566, 8, 81, 400};
    for(int i=0 ; i<10 ; i++)
        tree.insert(input[i]);
    tree.preOrder();
    tree.inOrder();
    cout<<tree.search(-999);
    return 0;
}