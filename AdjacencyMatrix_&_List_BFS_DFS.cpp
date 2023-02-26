#include <bits/stdc++.h>
using namespace std;

int vertArr[20][20];
int count = 0;

void displayMatrix(int v)
{
    int i, j;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            cout << vertArr[i][j] << " ";
        }
        cout << endl;
    }
}

void printList(vector<int> adj[], int V)
{
    for (int d = 0; d < V; ++d)
    {
        cout << "Vertex " << d << ":";
        for (int i = 0; i < adj[d].size(); i++)
        {
            cout << " -> " << adj[d][i];
        }
        printf("\n");
    }
}

void add_edge(int u, int v)
{
    vertArr[u][v] = 1;
    vertArr[v][u] = 1;
}
void add_edge_list(vector<int> adj[], int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

// BFS
class Graph
{
    int V;
    vector<list<int> > adj;

public:
    Graph(int V);
    void addEdge_bfs(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge_bfs(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    vector<bool> visited;
    visited.resize(V, false);

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (auto adjacent : adj[s])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

// DFS

class Graph2 {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;

	void addEdge_dfs(int v, int w);
	void DFS(int v);
};

void Graph2::addEdge_dfs(int v, int w)
{
	adj[v].push_back(w);
}

void Graph2::DFS(int v)
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}


main()
{
    int V, E, a, b;
    cin>>V>>E;

    vector<int> adj[V];

    Graph g(V);
    Graph2 g2;

    for (int i = 0; i < E; i++)
    {
        cin>>a>>b;
        add_edge(a, b);
        add_edge_list(adj,a, b);
        g.addEdge_bfs(a,b);
        g2.addEdge_dfs(a,b);
    }
    cout<<"Adjacency Matrix: \n";
    displayMatrix(V);
    cout<<"Adjacency List: \n";
    printList(adj, V);
    cout << "BFS: ";
    g.BFS(0);
    cout<<"\n";
    cout << "DFS: ";
    g2.DFS(0);

}
/**
input like

7 8
0 1
0 4
0 6
1 2
2 3
2 4
4 5
5 6

Graph:
  0
 /|\
1 4 6
|/|/
2 5
|
3
**/
