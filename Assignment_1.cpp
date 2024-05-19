#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;
    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class operations
{
public:

void swapSubtrees(node *temp)
{
    if(temp == NULL)
    {
        return;
    }
    
    // Swap the left and right subtrees
    node *tempNode = temp->left;
    temp->left = temp->right;
    temp->right = tempNode;
    
    // Recursively swap the subtrees of left and right children
    swapSubtrees(temp->left);
    swapSubtrees(temp->right);
}

    void preorder(node *temp)
    {
        if(temp==NULL)
        {
            return;
        }
        cout<<temp->data<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }

    void inorder(node *temp)
    {
        if(temp==NULL)
        {
            return;
        }
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }

    void postorder(node *temp)
    {
        if(temp==NULL)
        {
            return;
        }
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<" ";
    }

    int countNodes(node *temp)
    {
        if(temp == NULL)
        {
            return 0;
        }
        else
        {
            return countNodes(temp->left) + countNodes(temp->right) + 1;
        }
    }

    int countLeaves(node *temp)
    {
        if(temp == NULL)
        {
            return 0;
        }
        else if(temp->left == NULL && temp->right == NULL)
        {
            return 1;
        }
        else
        {
            return countLeaves(temp->left) + countLeaves(temp->right);
        }
    }

    int countInternalNodes(node *temp)
    {
        if(temp == NULL || (temp->left == NULL && temp->right == NULL))
        {
            return 0;
        }
        else
        {
            return countInternalNodes(temp->left) + countInternalNodes(temp->right) + 1;
        }
    }

    int height(node *temp)
    {
        if(temp==NULL)
        {
            return 0;
        }
        else
        {
            int lheight = height(temp->left);
            int rheight = height(temp->right);
            return(max(lheight,rheight)+1);
        }
    }
};

int main()
{
    node *root = new node(0);
    root->left = new node(1);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);

    operations op;
    cout<<"Preorder traversal of binary tree is : ";
    op.preorder(root);
    cout<<endl;
    cout<<"Inorder traversal of binary tree is : ";
    op.inorder(root);
    cout<<endl;
    cout<<"Postorder traversal of binary tree is : ";
    op.postorder(root);
    cout<<endl;
    cout<<"Number of nodes in binary tree is : "<<op.countNodes(root);
    cout<<endl;
    cout<<"Number of leaves in binary tree is : "<<op.countLeaves(root);
    cout<<endl;
    cout<<"Number of internal nodes in binary tree is : "<<op.countInternalNodes(root);
    cout<<endl;
    cout<<"Height of binary tree is : "<<op.height(root);
    cout<<endl;
    cout<<"Inorder traversal of binary tree after swapping is : ";
    op.swapSubtrees(root);
    op.inorder(root);
    cout<<endl;
}