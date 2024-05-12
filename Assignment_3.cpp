//Create an inordered threaded binary search tree. Perform inorder, preorder traversal without recursion and deletion of a node.
//Analyze time and space complexity of the algorithm.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    bool l_thread;
    bool r_thread;
};

class BST_threaded
{
private:
    Node* Root;
public:
    void create_root(int data){
        Root=new Node;
        Root->data=data;
        Root->l_thread= false;
        Root->r_thread=false;
        Root->left=NULL;
        Root->right=NULL;
        cout<<"Root created successfully !!"<< endl;
    }
    void insert_node(Node* root, Node* Newnode){
        if(Newnode->data < root->data){
            if(root->left==NULL || root->l_thread ==false){
                Newnode->left=root->left;           //copy
                Newnode->l_thread=root->l_thread;   //copy
                Newnode->right=root;
                Newnode->r_thread=true;
                root->left=Newnode;
                root->l_thread=true;
            }
            else
                insert_node(root->left,Newnode);
        }
        else{
            if(root->right==NULL || root->r_thread ==false){
                Newnode->right= root->right;       //copy
                Newnode->r_thread=root->r_thread;  //copy
                Newnode->left=root;
                Newnode->l_thread=true;
                root->right=Newnode;
                root->r_thread=true;

            }
            else
                insert_node(root->right,Newnode);
        }
    }
    void insertion(int cnt){
        Node* newnode;
        for(int i=0; i< cnt; i++){
            newnode= new Node;
            cout<<"Enter data of new node: ";
            cin>>newnode->data;
            insert_node(Root, newnode);
            cout<<"Node no. "<<i<<"  created!"<<endl;
        }
    }
    void inorder_display(){
        Node* current=Root;
        cout<<"The inorder traversal is: "<<endl;
        while(current->left)
        	current=current->left;
        while(current && current->right!=NULL){
        	cout<<current->data<<endl;
        	if(current->r_thread==true)
        		current=current->right;
        	else{
        		current=current->right;
        		while(current->left && current->l_thread==false)
        			current=current->left;
        	}
        }
        cout<<current->data<<endl;
        //cout<<"The inorder traversal has been completed..."<<endl;
    }
    void preorder_display(){
    	Node* current=Root;
    	cout<<"The preorder traversal is: "<<endl;
    	cout<<Root->data<<endl;
    	while(current && current->right!=NULL){
    		if(current->left && current->l_thread==false){
    			current=current->left;
    			cout<<current->data<<endl;
    		}
    		else{
    			while(current->r_thread==true)
    				current=current->right;
    			if(current->right){
    				current=current->right;
    				cout<<current->data<<endl;
    		}
    		}
    	}
    	//cout<<"The preorder traversal is complete..."<<endl;
    }
    void deletion(){
    	cout<<"Enter node to be deleted: ";
    	int key;
    	cin>>key;
    	Node* node= Root;	// node to be deleted
    	Node* parent= Root;	//parent of node to be deleted;
    	bool check=false;
    	while(node){
    		if(node->data==key){
    			check=true;
    			break;
    		}
    		else if(node->data>key && node->left && node->l_thread==false){
    			parent = node;
    			node=node->left;
    		}else if(node->data<key && node->right && node->r_thread == false){
    			parent = node;
    			node=node->right;
    		}else{
    			cout<<"Node to be deleted does not exit inside the tree!"<<endl;
    			break;
    		}
    	}
    	if(check==true){
    		if((node->l_thread==true && node->r_thread==true) ||(node->left==NULL && node->r_thread==true)||(node->right==NULL && node->l_thread==true)){
    			// Node with no children
    			if(node==parent->left){
    				parent->left=node->left;
    				parent->l_thread=node->l_thread;
    				delete node;
    			}else{
    				parent->right=node->right;
    				parent->r_thread=node->r_thread;
    				delete node;
    			}
    		}

    		else if(node->l_thread == false && node->r_thread == false){
    			// Node with two children
    			Node* next=node->right;
    			while(next->left && next ->l_thread==false)
                    next=next->left;
                if(next==node->right){
                    node->data=next->data;
                    node->right=next->right;
                    node->r_thread=next->r_thread;
                    delete next;
                }else{
                    node->data=next->data;
                    next->right->left=node;
                    next->right->l_thread=true;
                    delete next;
                }
    		}

    		else{
    			//Node with one child
    			if(node==parent->left){
                    if(node->left && node->l_thread ==false){
                        //"Node at left & Single child at left"
                        parent->left=node->left;
                        if(node->left->right==node)
                            node->left->right=parent;
                        delete node;
                    }else{
                        //cout<<"Node at left and single child at right"
                        parent->left=node->right;
                        if(node->right->left==node)
                            node->right->left=parent;
                        delete node;
                    }
    			}
                else{
                    if(node->left && node->l_thread==false){
                        //cout<<"Node at left & single child at left"
                        parent->right=node->left;
                        if(node->left->right==node)
                            node->left->right=parent;
                        delete node;
                    }else{
                        //cout<<"Node at right & single child at right"
                        parent->right=node->right;
                        if(node->right->left==node)
                            node->right->left=parent;
                        delete node;
                    }
                }
            }
        }
    }

};
int main()
{
    BST_threaded T1;
    T1.create_root(0);
    T1.insertion(11);
    T1.inorder_display();
    T1.preorder_display();
    T1.deletion();
    T1.preorder_display();
    T1.deletion();
    T1.preorder_display();
    T1.deletion();
    T1.preorder_display();
    T1.deletion();
    T1.preorder_display();
    T1.deletion();
    T1.preorder_display();
    cout<<"Exhaust";
    return 0;
}