/*
Represent a given graph using adjacency list to perform BFS and DFS. 
Use the map of the area around the college as a graph.
Identify the prominent land marks as nodes and perform DFS and BFS on that.
*/
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
 
class Node
{
    string data;
    Node *down;
    Node *right;
    Node()
    {
        data="";
        down=NULL;
        right=NULL;
    }
friend class Graph;
};
 
 
class Graph
{
    public:
    int tot=0;
    Node *head=new Node;
 
    void Create()
    {
        cout<<"Enter number of vertices:";
        ll a;
        cin>>tot;
        cout<<endl;
        a=tot;
        Node *temp=head;
        while(a--)
        {
            string str;
            ll b;
            cout<<"Enter name of city and number of connected cities: ";
            cin>>str>>b;
            cout<<endl;
            Node *k=new Node;
            k->data=str;
            temp->down=k;
            temp=k;
            Node *p=k;
            while(b--)
            {
                cout<<"Enter connected city: ";
                string hk;
                cin>>hk;
                cout<<endl;
                Node *New=new Node;
                New->data=hk;
                temp->right=New;
                temp=New;
            }
            temp=p;
        }
    }
    void Display()
    {
        Node *temp=head->down;
        while(temp!=NULL)
        {
            Node *t2=temp->right;
            cout<<temp->data;
            while(t2!=NULL)
            {
                cout<<"->"<<t2->data;
                t2=t2->right;
            }
            temp=temp->down;cout<<endl;
        }
 
    };
    void Degree()
    {
        cout<<head->down->data<<endl;
        map<string,ll>m;
        Node *temp=head->down;
        while(temp!=NULL){
            Node *t2=temp->right;
            ll count=0;
            while(t2!=NULL)
            {
                count++;
                t2=t2->right;
            }
            m[temp->data]=count;
            temp=temp->down;
        }
        for(auto &it:m)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
 
    };
 
    void DFS()
    {
        set<string>s;
        stack<string>se;
        string d = head->down->data;
        se.push(head->down->data);
        while(!se.empty())
        {
            string x=se.top();
            se.pop();
            if(s.find(x)==s.end())
            {
                cout<<x<<" ";
                Node *temp=head->down;
                s.insert(x);
                while(temp->data!=x)
                {
                    temp=temp->down;
                }
                while(temp!=NULL)
                {
                    se.push(temp->data);
                    temp=temp->right;
                }
            }
        }
    }
 
    void BFS()
    {
        set<string>s;
        queue<string>se;
        string d = head->down->data;
        se.push(head->down->data);
        while(!se.empty())
        {
            string x=se.front();
            se.pop();
            if(s.find(x)==s.end())
            {
                cout<<x<<" ";
                Node *temp=head->down;
                s.insert(x);
                while(temp->data!=x)
                {
                    temp=temp->down;
                }
                while(temp!=NULL)
                {
                    se.push(temp->data);
                    temp=temp->right;
                }
            }
        }
    }
};
 
int main()
{
    Graph g;
    g.Create();
    cout<<"Adjacency matric of graph\n";
    g.Display();
    // cout<<"Degree of each vertex: \n";
    // g.Degree();
    cout<<"DFS : ";
    g.DFS();
    cout<<endl;
    cout<<"BFS : ";
    g.BFS();
    cout<<endl;
}