 #include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int index;
    ListNode *next;
    ListNode(int index)
    {
        this->index = index;
        this->next = NULL;
    }
};
struct GraphNode
{
    int index;
    string data;
    ListNode *list_head;
    GraphNode()
    {
        data = "";
        index = -1;
        list_head = NULL;
    }
    GraphNode(int index, string data)
    {
        this->index = index;
        this->data = data;
        list_head = NULL;
    }
};
class Graph
{
    int capacity;
    GraphNode **array;
    int **adj_matrix;

public:
    Graph(int capacity)
    {
        this->capacity = capacity;
        array = new GraphNode *[capacity];
        for (int i = 0; i < capacity; i++)
            array[i] = NULL;
        adj_matrix = new int *[capacity];
        for (int i = 0; i < capacity; i++)
            adj_matrix[i] = new int[capacity];
        for (int i = 0; i < capacity; i++)
            for (int j = 0; j < capacity; j++)
                adj_matrix[i][j] = INT_MAX;
    }
    void addEdge();
    void removeEdge();
    void displayList();
    void displayMatrix();
    void prims();
};
void Graph ::addEdge()
{
    cout << endl;
    cout << "ADDING EDGE" << endl;
    int index_1 = -1;
    int index_2 = -1;
    string data_1 = "";
    string data_2 = "";
    GraphNode *pointer_1;
    GraphNode *pointer_2;
    cout << "Enter first node index less than capacity " << capacity << ": ";
    cin >> index_1;
    if (index_1 >= capacity)
    {
        cout << "OVERFLOW!" << endl;
        return;
    }
    if (array[index_1])
    {
        pointer_1 = array[index_1];
        data_1 = pointer_1->data;
    }
    else
    {
        cout << "Enter first node data: ";
        cin >> data_1;
        pointer_1 = new GraphNode(index_1, data_1);
        array[index_1] = pointer_1;
    }
    cout << "Enter second node index less than capacity " << capacity << ": ";
    cin >> index_2;
    if (index_2 >= capacity)
    {
        cout << "OVERFLOW!" << endl;
        return;
    }
    if (array[index_2])
    {
        pointer_2 = array[index_2];
        data_2 = pointer_2->data;
    }
    else
    {
        cout << "Enter second node data: ";
        cin >> data_2;
        pointer_2 = new GraphNode(index_2, data_2);
        array[index_2] = pointer_2;
    }
    ListNode *traverser_1 = pointer_1->list_head;
    ListNode *traverser_2 = pointer_2->list_head;
    if (!traverser_1)
        pointer_1->list_head = new ListNode(index_2);
    else
    {
        while (traverser_1->next)
            traverser_1 = traverser_1->next;
        traverser_1->next = new ListNode(index_2);
    }
    if (!traverser_2)
        pointer_2->list_head = new ListNode(index_1);
    else
    {
        while (traverser_2->next)
            traverser_2 = traverser_2->next;
        traverser_2->next = new ListNode(index_1);
    }
    int weight = 0;
    cout << "Enter the weight: ";
    cin >> weight;
    adj_matrix[index_1][index_2] = weight;
    adj_matrix[index_2][index_1] = weight;
    cout << "ADDED EDGE BETWEEN \"" << array[index_1]->data << "\" AND \"" << array[index_2]->data << "\"." << endl;
}
void Graph ::removeEdge()
{
    cout << endl;
    cout << "REMOVING EDGE" << endl;
    int index_1 = -1;
    int index_2 = -1;
    GraphNode *pointer_1;
    GraphNode *pointer_2;
    cout << "Enter first node index less than capacity " << capacity << ": ";
    cin >> index_1;
    if (index_1 >= capacity || array[index_1] == NULL)
    {
        cout << "No corresponding node discovered." << endl;
        return;
    }
    else
        pointer_1 = array[index_1];
    cout << "Enter second node index less than capacity " << capacity << ": ";
    cin >> index_2;
    if (index_2 >= capacity || array[index_2] == NULL)
    {
        cout << "No corresponding node discovered." << endl;
        return;
    }
    else
        pointer_2 = array[index_2];
    ListNode *traverser_1 = pointer_1->list_head;
    ListNode *traverser_2 = pointer_2->list_head;
    if (!traverser_1 || !traverser_2)
    {
        cout << "No edge detected." << endl;
        return;
    }
    if (traverser_1->index == index_2)
    {
        pointer_1->list_head = traverser_1->next;
        delete traverser_1;
    }
    else
    {
        while (traverser_1->next)
        {
            if (traverser_1->next->index == index_2)
                break;
            traverser_1 = traverser_1->next;
        }
        if (traverser_1->next == NULL)
        {
            cout << "No edge detected." << endl;
            return;
        }
        else
        {
            ListNode *temp = traverser_1->next;
            traverser_1->next = traverser_1->next->next;
            delete temp;
        }
    }
    if (traverser_2->index == index_1)
    {
        pointer_2->list_head = traverser_2->next;
        delete traverser_2;
    }
    else
    {
        while (traverser_2->next)
        {
            if (traverser_2->next->index == index_1)
                break;
            traverser_2 = traverser_2->next;
        }
        if (traverser_2->next == NULL)
        {
            cout << "No edge detected." << endl;
            return;
        }
        else
        {
            ListNode *temp = traverser_2->next;
            traverser_2->next = traverser_2->next->next;
            delete temp;
        }
    }
    adj_matrix[index_1][index_2] = 0;
    adj_matrix[index_2][index_1] = 0;
    cout << "REMOVED EDGE BETWEEN \"" << array[index_1]->data << "\" AND \"" << array[index_2]->data << "\"." << endl;
}
void Graph ::displayList()
{
    cout << endl;
    cout << "ADJASCENCY LIST" << endl;
    for (int i = 0; i < capacity; i++)
    {
        cout << i << " ";
        if (array[i])
            cout << array[i]->data << " --> ";
        else
        {
            cout << endl;
            continue;
        }
        ListNode *traverser = array[i]->list_head;
        while (traverser)
        {
            cout << array[traverser->index]->data << " --> ";
            traverser = traverser->next;
        }
        cout << endl;
    }
}
void Graph ::displayMatrix()
{
    for (int i = 0; i < capacity; i++)
    {
        for (int j = 0; j < capacity; j++)
            cout << adj_matrix[i][j] << "\t";
        cout << endl;
    }
}
void Graph ::prims()
{
    int result_matrix[capacity][capacity];
    bool visited_matrix[capacity][capacity];
    for (int i = 0; i < capacity; i++)
        for (int j = 0; j < capacity; j++)
        {
            result_matrix[i][j] = INT_MAX;
            visited_matrix[i][j] = false;
        }
    set<int> chosen;
    int min_edge = INT_MAX;
    int min_vertex_1 = -1;
    int min_vertex_2 = -1;
    for (int i = 0; i < capacity; i++)
        for (int j = 0; j < capacity; j++)
            if (adj_matrix[i][j] < min_edge)
            {
                min_vertex_1 = i;
                min_vertex_2 = j;
                min_edge = adj_matrix[i][j];
            }
    chosen.insert(min_vertex_1);
    chosen.insert(min_vertex_2);
    visited_matrix[min_vertex_1][min_vertex_2] = true;
    visited_matrix[min_vertex_2][min_vertex_1] = true;
    result_matrix[min_vertex_1][min_vertex_2] = min_edge;
    result_matrix[min_vertex_2][min_vertex_1] = min_edge;
    while (chosen.size() <= capacity)
    {
        int min_edge_weight = INT_MAX;
        int vertex_1 = -1;
        int vertex_2 = -1;
        for (auto it = chosen.begin() ; it!=chosen.end() ; it++)
        {
            int i = *it;
            for (int j = 0; j < capacity; j++)
            {
                if (adj_matrix[i][j] < min_edge_weight && chosen.find(j) == chosen.end() && visited_matrix[i][j] == false && i!=j)
                {
                    min_edge_weight = adj_matrix[i][j];
                    vertex_1 = i;
                    vertex_2 = j;
                }
            }
        }
        result_matrix[vertex_1][vertex_2] = min_edge_weight;
        result_matrix[vertex_2][vertex_1] = min_edge_weight;
        visited_matrix[vertex_1][vertex_2] = true;
        visited_matrix[vertex_2][vertex_1] = true;
        chosen.insert(vertex_2);
    }
    cout << endl;
    cout << "RESULT MATIRX" << endl;
    for (int i = 0; i < capacity; i++)
    {
        for (int j = 0; j < capacity; j++)
            cout << result_matrix[i][j] << "\t";
        cout << endl;
    }
    cout<<endl;
    for (int i = 0; i < capacity; i++)
    {
        for (int j = 0; j < capacity; j++)
            cout << visited_matrix[i][j] << "\t";
        cout << endl;
    }
}
int main()
{
    int capacity = 0;
    cout << "Enter the capacity for the graph: ";
    cin >> capacity;
    Graph g1(capacity);
    cout << "ENTER CHOICE: \n 1)Add Edge \n 2)Remove Edge \n 3)Display List \n 4)Display Matrix \n 5)MST \n 6)Quit \n";
    int choice = 0;
    cin >> choice;
    while (choice != 6)
    {
        if (choice == 1)
            g1.addEdge();
        else if (choice == 2)
            g1.removeEdge();
        else if (choice == 3)
            g1.displayList();
        else if (choice == 4)
            g1.displayMatrix();
        else if (choice == 5)
            g1.prims();
        else
            cout << "INVALID CHOICE!\n";
        cout << "ENTER CHOICE: ";
        cin >> choice;
    }
    cout << endl;
    cout << "THANK YOU FOR USING AN AARYA BHAVE CODE FILE.";
    return 0;
}