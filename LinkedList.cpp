#include <iostream>
using namespace std;
struct vertex
{
    int data;
    vertex* left;
    vertex* right;
};

struct Node
{
    int data;
    Node* next;
};

class Tree
{
public:
    vertex* root;
    int len;  // Number of elements present in graph
    void build_bst(Node* head);  // Builds a BST using linked list
    void insert(vertex* itr, int data);
    void display(vertex* itr);
    bool search(vertex* itr, int a);   // Searche element a
    int pick_median(Node* head);
    // and stores it in array A[]
    Tree(int n)
    {
        len = n;
        root = new vertex();
    }
};

void Tree::display(vertex* itr)
{
    if(itr != NULL)
    {
        cout << itr -> data << ' ';
        // Iteration of graph
        if(itr -> left != NULL)
        {
            display(itr -> left);
        }
        if(itr -> right != NULL)
        {
            display(itr -> right);
        }
    }
}

void display(Node* head)
{
    while(head != NULL)
    {
        cout << head -> data << ' ';
        head = head -> next;
    }
    cout << '\n';
}

Node* sorted_insert(Node* head, int n)
{
    if(head->data==0)
    {
        head->data = n;
    }
    else if(head->next == NULL)
    {
        Node* temp = new Node();
        temp->data = n;
        if(head->data<n)
        {
            head->next = temp;
            return head;
        }
        else
        {
            temp->next = head;
            return temp;
        }
    }
    else
    {
        Node* temp = new Node();
        temp->data = n;
        Node* itr = head;
        if(n < itr -> data)
        {
            temp -> next = head;
            return temp;
        }
        while(n > (itr -> next) -> data)
        {
            itr = itr -> next;
            if(itr -> next == NULL)
            {
                itr->next = temp;
                return head;
            }
        }
        temp->next = itr->next;
        itr->next = temp;
    }
    return head;
}

Node* linked_sort(Node* head)
{
    Node* itr = head;
    Node* sorted_list = new Node();
    while(itr != NULL)
    {
        sorted_list = sorted_insert(sorted_list, itr -> data);
        itr = itr -> next;
    }
    return sorted_list;
}

void Tree::insert(vertex* itr, int data)
{
    // display(itr);
    if(data<itr->data)
    {
        if(itr->left!=NULL)
        {
            insert(itr->left, data);
        }
        else
        {
            vertex* temp = new vertex();
            temp->data = data;
            itr->left = temp;
        }
    }
    else
    {
        if(itr->right!=NULL)
        {
            insert(itr->right, data);
        }
        else
        {
            vertex* temp = new vertex();
            temp->data = data;
            itr->right = temp;
        }
    }
}

int list_ele(Node* head, int i)
{
    for(int j=0;j<i;j++)
    {
        head = head->next;
    }
    return head->data;
}

int Tree::pick_median(Node* head)
{
    int pos = len/2;    // Pick median as root
    int a = list_ele(head,pos);
    for(int j=0;j<pos-1;j++)
    {
        head = head->next;
    }
    Node* temp = head->next;
    head->next = temp->next;
    free(temp);
    return a;
}

void Tree::build_bst(Node* head)
{
    int a;

    Node* itr = head;  // Iteration of linked list
    root -> data = pick_median(head);
    while(itr != NULL)
    {
        insert(root, itr -> data);
        itr = itr -> next;
    }
}

Node* create_linkedlist(int n)
{
    Node* head = new Node();
    Node* itr= head;
    cout << "Sample Input : 1 2 3 4 5" << '\n';
    cout << "Enter elements present in linked list : ";
    int a;
    cin >> a;
    head -> data = a;
    for(int i = 0; i < n - 1; i++)
    {
        int a;
        cin >> a;
        Node* temp = new Node();
        temp -> data = a;
        temp -> next = NULL;
        itr -> next = temp;
        itr = itr -> next;
    }
    return head;
}

// Time Complexity of BST in average is O(lg n)
bool Tree::search(vertex* itr, int a)
{

    if(itr->data == a)
    {
        return true;
    }
    else if(itr -> left == NULL and itr -> right == NULL)
    {
        return false;
    }
    else if(itr -> data > a)
    {
        return search(itr -> left, a);
    }
    else if(itr -> data < a)
    {
        return search(itr -> right, a);
    }
    return false;
}

int main()
{
    cout << "Enter no. of elements present in linked list: ";
    int n;
    cin >> n;
    // Number of elements should be atleast 1
    Node* head = create_linkedlist(n);
    Node* sorted = linked_sort(head);
    // display(sorted);
    Tree bst(n);
    bst.build_bst(sorted);
    bst.display(bst.root);
    cout << '\n';
    cout << "Enter the number to be searched : ";
    int s;
    cin >> s;
    if(bst.search(bst.root, s))
    {
        cout << "The element exists\n";
    }
    else
    {
        cout << "The element doesn't exists\n";
    }
    return 0;
}
