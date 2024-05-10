#include <iostream>
using namespace std;


class Node
{
	public:
	int data;
	Node *left;
	Node *right;
};


class BST
{
public:
Node *create(Node *temp)
{
	Node *newnode;
	newnode = new Node;
	cout<<"Enter Root Value : ";
	cin>>newnode->data;
	newnode->left=NULL;
	newnode->right=NULL;
	if(temp==NULL)
	{
		temp=newnode;
	}
	else
	{
		cout<<"Root is already present!";
	}
	return temp;
}

	
void insert(Node *temp, Node *newnode)
{
	if(newnode->data<temp->data)
	{
		if(temp->left==NULL)
		{
			temp->left=newnode;
		}
		else
		{
			insert(temp->left,newnode);
		}
	}
	else
	{
		if(temp->right==NULL)
		{
			temp->right=newnode;
		}
		else
		{
			insert(temp->right,newnode);
		}
	}
}

void inorder(Node *temp)
{
	if(temp != NULL)
  	{
   		inorder(temp->left);
   		cout<<temp->data<<" ";
   		inorder(temp->right);
  	}
} 

void postorder(Node *temp)
{
  	if(temp != NULL)
  	{
   		postorder(temp->left);
   		postorder(temp->right);
   		cout<<temp->data<<" ";
  	}	
}
 
void preorder(Node *temp)
{
  	if(temp != NULL)
  	{
   		cout<<temp->data<<" ";
   		preorder(temp->left);
   		preorder(temp->right);
  	}
} 

void min(Node *temp)
{
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	cout<<temp->data;
}

void max(Node *temp)
{
	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	cout<<temp->data;
}

void height(Node *temp)
{
	int x=0;
	int y=0;
	while(temp->left!=NULL)
	{
		temp=temp->left;
		x++;
	}
	while(temp->right!=NULL)
	{
		temp=temp->right;
		y++;
	}
	if(x>y)
	{
		cout<<x;
	}
	else
	{
		cout<<y;
	}
}
};


int main()
{
	BST b;
	int i,count;
	Node *root;
    cout<<"Enter Root Data : ";
    cin>>root->data;
    root->left=NULL;
    root->right=NULL;
	cout<<"No. of Nodes to Insert : ";
	cin>>count;
	for(i=0;i<count;i++)
	{
		Node *newnode;
		newnode=new Node;
		cout<<"Enter data to be inserted : ";
		cin>>newnode->data;
		newnode->left=NULL;
		newnode->right=NULL;
		b.insert(root,newnode);
	}
	cout<<endl;

	cout<<"Height : ";
	b.height(root);
	cout<<endl<<endl;

	cout<<"Inorder Traversal : ";
	b.inorder(root);
	cout<<endl;
	cout<<"Preorder Traversal : ";
	b.preorder(root);
	cout<<endl;
	cout<<"Postorder Traversal : ";
	b.postorder(root);
	cout<<endl<<endl;

	cout<<"Minimum Value Element : ";
	b.min(root);
	cout<<endl;
	cout<<"Maximum Value Element : ";
	b.max(root);
	cout<<endl;
	return 0;
}