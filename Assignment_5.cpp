/*
Implement all the functions of a dictionary (ADT) using open
hashing technique: separate chaining using linked list Data: Set of
(key, value) pairs, Keys are mapped to values, Keys must be
comparable, and Keys must be unique. Standard Operations: Insert
(key, value), Find(key), Delete(key).
*/

#include<iostream>
using namespace std;
 
class Node
{
    int key=0;
    string value="";
    Node *next=NULL;
    friend class Dict;
};
 
class Dict
{
    public:
    Node *arr=new Node[10];
 
    void insertValue(int key,string value)
    {
        int index=key%10;
        if(arr[index].value=="")
        {
            arr[index].key=key;
            arr[index].value=value;
        } 
        else
        {
            Node *New=new Node;
            New->key=key;
            New->value=value;
            if(arr[index].next==NULL)
            {
                arr[index].next=New;
            }
            else
            {
                Node *temp=arr[index].next;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=New;
            }
        }
    }
 
    void Display()
    {
        for(int i=0;i<10;i++)
        {
            cout<<"("<<arr[i].key<<","<<arr[i].value<<")";
            Node *temp=arr[i].next;
            while(temp!=NULL)
            {
                cout<<"->"<<"("<<temp->key<<","<<temp->value<<")";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
 
    void search(int key)
    {
        int index=key%10;
        int compa=1;
        if(arr[index].key==key)
        {
            cout<<"("<<arr[index].key<<","<<arr[index].value<<") is present."<<endl;
            cout<<"Number of Comparisons Required : "<<compa<<endl;
        }
        else
        {
            Node *temp=arr[index].next;
            while(temp!=NULL)
            {
                compa++;
                if(temp->key==key)
                {
                    cout<<"("<<temp->key<<","<<temp->value<<") with comparisions: "<<compa<<endl;
                    return;
                }
                temp=temp->next;
            }
            cout<<"No such value is present in dictionary."<<endl;
            cout<<"Number of Comparisons Required : "<<compa<<"\n";
        }
 
    }
 
    void Delete(int key)
    {
        int index=key%10;
        if(arr[index].key==key)
        {
            if(arr[index].next==NULL)
            {
                arr[index].key=0;
                arr[index].value="";
            }
            else
            {
                Node *temp=arr[index].next;
                arr[index].key=temp->key;
                arr[index].value=temp->value;
                arr[index].next=temp->next;
                temp->next=NULL;
                delete temp;
            }
        }
        else
        {
            Node *temp=arr[index].next;
            if(temp==NULL)
            {
                cout<<"Key not Found!";
                return;
            }
            if(temp->key==key)
            {
                arr[index].next=temp->next;
                temp->next=NULL;
                delete temp;
            }
            else
            {
                while(temp->next!=NULL)
                {
                    if(temp->next->key==key)
                    {
                        Node *temp1=temp;
                        temp=temp->next;
                        temp1->next=temp->next;
                        delete temp;
                        return;
                    }
                    temp=temp->next;
                }
                cout<<"Key not found";
            }
        }
    }
};
 
int main()
{
    Dict a;
    a.insertValue(7,"Seven");
    a.insertValue(27,"Twenty Seven");
    a.insertValue(37,"Thirty Seven");
    a.insertValue(15,"Fifteen");
    a.insertValue(25,"Twenty Five");
    a.insertValue(3,"Three");
    a.Display();
    cout<<"\n\n";
    a.search(15);
    cout<<"\n";
    a.search(9);
    a.Delete(7);
    cout<<"\n\nDisplaying after Deletion : \n";
    a.Display();
}