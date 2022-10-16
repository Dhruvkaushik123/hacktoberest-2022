#include <iostream>
using namespace std;
struct Edge
{
    int source;
    int dest;
    int weight;
};
class Graph
{
public:
    int v, e;            // number of vertices and edges in graph
    Edge* edges;        // Array of edges
    void build_graph();
    int edge_vertex(int a, int b);  // returns weight of edge between vertex, vertex a and vertex b, returns -1 if doesn't exists
    int min_Dist(int dist[], bool mst[]);
    void dijkstra(int source);
    Graph(int a, int b)
    {
        v=a;
        e=b;
        edges = new Edge[e];
    }
};

int Graph::edge_vertex(int a, int b)
{
    for(int i = 0; i < e; i++)
    {
        if(edges[i].source == a and edges[i].dest == b)
        {
            return edges[i].weight;
        }
        else if(edges[i].source == b and edges[i].dest == a)
        {
            return edges[i].weight;
        }
    }
    return -1;
}

int Graph::min_Dist(int dist[], bool mst[])
{
    int min = INT32_MAX, index;
    for (int itr = 0; itr < v; itr++)
        if (mst[itr] == false && dist[itr] <= min)
            min = dist[itr], index = itr;
    return index;
}

// It takes adjeceny matrix as input, and inserts into edges
void Graph::build_graph()
{
    cout << "Enter adjecency-matrix \n";
    int k = 0;
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            int w;
            cin >> w;
            edges[k].weight = w;
            edges[k].source = i;
            edges[k].dest = j;
            k = k + 1;
        }
    }
}

void disp_arr(int A[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << A[i] << ' ';
    }
    cout << '\n';
}

void disp_arr(bool A[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << A[i] << ' ';
    }
    cout << '\n';
}

void Graph::dijkstra(int source)
{
    int dist[v];   // stores final destination weights from source
    bool mst[v];   // true if the vertex already in minimum spanning tree
    for(int i = 0; i < v; i++)
    {
        dist[i] = INT32_MAX;
        mst[i] = false;
    }
    dist[source] = 0;   // The source is at 0 from itself
    for(int i = 0; i < v-1; i++)
    {
        int u = min_Dist(dist, mst);   // Vertex with least dist is picked
        mst[u] = true;   // It is added to mst
        for(int j = 0; j < v; j++)
        {
            if (!mst[j] && edge_vertex(u,j)!= -1 && dist[u] != INT32_MAX
                && dist[u] + edge_vertex(u, j)< dist[j])
                {
                    dist[j] = dist[u] + edge_vertex(u, j);
                }
        }
    }
    cout << "The shortest path from source " << source << " is\n";
    for(int i = 0; i < v; i++)
    {
        cout << i+1 << " " << dist[i] << '\n';
    }
}
int main()
{
    cout << "Enter number of vertices present in graph: ";
    int v,e;
    cin >> v;
    cout << "Enter number of edges present in graph: ";
    cin >> e;
    Graph graph(v, e);
    graph.build_graph();
    while(true)
    {
        cout << "Enter 0 to quit\n";
        cout << "Enter 1 for dijkstsra's algorithm\n";
        int ans;
        cin >> ans;
        if(ans == 1)
        {
            cout << "Enter source element of graph: ";
            int source;
            cin >> source;
            graph.dijkstra(source - 1);
        }
        else if(ans == 0)
        {
            cout << "Program is quitting...\n";
            break;
        }
        else
        {
            cout << "Please Enter again\n";
        }
    }
}
