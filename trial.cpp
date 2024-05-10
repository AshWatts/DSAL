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

	node* insert(node* root, int value)
	{
		if(root == NULL)
		{
			return new node(value);
		}
		else if(value < root->data)
		{
			root->left = insert(root->left, value);
		}
		else
		{
			root->right = insert(root->right, value);
		}
		return root;
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
	node *root = NULL;
	operations op;

	int n;
	cout << "Enter the number of nodes: ";
	cin >> n;

	cout << "Enter the values of the nodes: ";
	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		root = op.insert(root, value);
	}

	cout << "Preorder traversal of binary tree is : ";
	op.preorder(root);
	cout << endl;
	cout << "Inorder traversal of binary tree is : ";
	op.inorder(root);
	cout << endl;
	cout << "Postorder traversal of binary tree is : ";
	op.postorder(root);
	cout << endl;
	cout << "Number of nodes in binary tree is : " << op.countNodes(root);
	cout << endl;
	cout << "Number of leaves in binary tree is : " << op.countLeaves(root);
	cout << endl;
	cout << "Number of internal nodes in binary tree is : " << op.countInternalNodes(root);
	cout << endl;
	cout << "Height of binary tree is : " << op.height(root);
	cout << endl;
}