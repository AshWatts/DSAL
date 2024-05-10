/* 	Implement all the functions of a dictionary (ADT) using open
	hashing technique: separate chaining using linked list Data: Set of
	(key, value) pairs, Keys are mapped to values, Keys must be
	comparable, and Keys must be unique.
	Standard Operations:
	Insert (key, value), Find(key), Delete(key) 	*/

#include <bits./stdc++.h>
using namespace std;

class Node{
public:
	char value[20];
	int key;
	Node* next;
};

class Open_Hashing{
private:
	int TableSize=10;
	Node* HT[10];
public:
    Open_Hashing(){
        for(int i=0; i<TableSize;i++)
        {
            HT[i]=NULL;
        }
    }
	//insert
	void insertion(){
        int number;
        cout<<"Enter the number of records you want to enter: ";
        cin>>number;
        Node* Newnode;
        int index;
        Node* temp;
        for(int i=0; i<number; i++){
            Newnode = new Node;
            cout<<"Enter the key: ";
            cin>>Newnode->key;
            cout<<"Enter the value: ";
            cin>>Newnode->value;
            Newnode->next=NULL;
            index= (Newnode->key) % TableSize;

            if(HT[index]==NULL){
                HT[index]=Newnode;
                //cout<<HT[index]->key<<" : "<<HT[index]->value<<endl;
            }
            else{
                temp= HT[index];
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=Newnode;
            }

        }
	}

	//display
	void display(){
		Node* temp;
		for(int index=0; index<TableSize; index++){
			cout<<endl;
			cout<<index<<" == ";
			temp= HT[index];
			while(temp!=NULL){
				cout.width(4);
				cout.setf(ios::left, ios::adjustfield);
				cout<<temp->key<<" : ";
				cout.width(25);
				cout.setf(ios::left, ios::adjustfield);
				cout<<temp->value<<" --> ";
                temp=temp->next;
			}
			cout<<"NULL"<<endl;
		}
	}
	//Find
	void Find(){
		int key;
		cout<<"Enter the key you want to search: ";
		cin>>key;
		Node* curr;
		bool check=false;
		int index= key % TableSize;
		curr=HT[index];
		while(curr!=NULL){
			if(curr->key== key){
				cout<<"Key Found! Corresponding value is: "<<curr->value<<endl;
				check =true;
				break;
			}
			else{
				curr=curr->next;
			}
		}
		if(check==false){
			cout<<"Key not found in the hash table..."<<endl;
		}
	}
	//Delete
	void deletion(){
		int key;
		cout<<"Enter the key you want to delete: ";
		cin>>key;
		int index=key%TableSize;
		Node* curr;
		Node*prev;
		curr=HT[index];
		bool check=false;
		while(curr!=NULL){
			if(curr->key ==key){
				check=true;
				break;
			}
			else{
				prev=curr;
				curr=curr->next;
			}
		}
		if(check==true){
			if(curr==HT[index]){
				HT[index]=curr->next;
				delete curr;
			}
			else{
				prev->next=curr->next;
				delete curr;
			}
		}
		else
			cout<<"Node to be deleted not found inside the hash table."<<endl;
	}
};
int main() {
	Open_Hashing H1;
	H1.insertion();
	H1.display();
	H1.Find();
	H1.Find();
	H1.Find();
	H1.Find();
	H1.Find();
	H1.deletion();
	H1.deletion();
	H1.deletion();
	H1.deletion();
	H1.deletion();
	H1.display();
	return 0;
}