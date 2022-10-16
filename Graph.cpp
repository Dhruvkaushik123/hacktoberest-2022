#include <iostream>
#include <cmath>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Graph
{
public:
    Node* root;
    int len;            // Number of elements present in graph
    int in_order[1000]; // Number of elements, graph can be built
    void build_graph();
    void insert(Node* ins, int data);
    void display(Node* ins);
    int inorder_trav(Node* ins, int k = 0); // creates inorder traversed elements and stores it in array A[]
    Graph(int n)
    {
        len = n;
        root = new Node();
    }
};

void Graph::insert(Node* ins, int data)
{
    if(data < ins -> data)
    {
        if(ins -> left != NULL)
        {
            insert(ins -> left, data);
        }
        else
        {
            Node* temp = new Node();
            temp -> data = data;
            ins -> left = temp;
        }
    }
    else
    {
        if(ins -> right != NULL)
        {
            insert(ins -> right, data);
        }
        else
        {
            Node* temp = new Node();
            temp -> data = data;
            ins -> right = temp;
        }
    }
}

// Visualising graph in Preorder Traversal
void Graph::display(Node* ins)
{
    if(ins != NULL)
    {
        cout << ins -> data << ' ';
        // Iteration of graph
        if(ins -> left != NULL)
        {
            display(ins -> left);
        }
        if(ins -> right != NULL)
        {
            display(ins -> right);
        }
    }
}

void Graph::build_graph()
{
    cout << "Sample Elements : 1 2 3 4 5" << '\n';
    cout << "Enter root of the given tree: ";
    int a;
    cin >> a;
    root -> data = a;

    cout << "Enter elements present in Binary Search Tree : ";
    for(int i = 0; i < len-1; i++)
    {
        int a;
        cin >> a;
        insert(root, a);
    }
}

int Graph::inorder_trav(Node* ins, int k)
{
    if(ins -> left != NULL)
    {
        k = inorder_trav(ins -> left, k);
    }
    in_order[k] = ins -> data;
    k = k+1;
    if(ins -> right!= NULL)
    {
        k = inorder_trav(ins -> right,k);
    }
    return k;
}

int main()
{
    cout << "Enter number of elements present in the BST: ";
    int n;
    cin >> n;

    Graph graph(n);
    graph.build_graph();
    graph.display(graph.root);
    cout << '\n';
    int A[n];
    int none = graph.inorder_trav(graph.root,0);
    for(int i = 0; i < n; i++)
    {
        cout << graph.in_order[i] << ' ';
    }
    cout << '\n';
    // The smallest element, largest element and median can be calculated
    int median;
    if(n%2 == 0)
    {
        median = graph.in_order[n/2];
    }
    else
    {
        median = (graph.in_order[n/2] + graph.in_order[n/2+1])/2;
    }
    // The sub tree has only 3 elements
    Graph sub_tree(3);
    sub_tree.root -> data = median;
    sub_tree.insert(sub_tree.root,graph.in_order[0]); // Insert smallest element
    sub_tree.insert(sub_tree.root,graph.in_order[n-1]); // Insert largest element

    sub_tree.display(sub_tree.root);
    cout << "\n";
}
