#include<bits/stdc++.h>
using namespace std;

int timer =0;

void DFS_VISIT(int u, vector<int> adj[], vector<string>& color, vector<int>& parent, vector<int>& d, vector<int>& f){
    timer++;
    d[u] = timer;
    color[u]= "GRAY";
    for (int v : adj[u]){
        if (color[v] == "WHITE"){
            parent[v] = u;
            DFS_VISIT(v, adj, color, parent, d, f);
        }
    }
    color[u] = "BLACK";
    timer++;
    f[u] = timer;
}

void DFS(int V, vector<int> adj[])
{
    vector<string> color(V, "WHITE");
    vector<int> parent(V, -1);
    vector<int> d(V, 0);
    vector<int> f(V, 0);

    timer = 0;

    // Check every vertex
    for (int u = 0; u < V; u++)
    {
        if (color[u] == "WHITE")
        {
            DFS_VISIT(u, adj, color, parent, d, f);
        }
    }

    cout << "\nVertex\tParent\tDiscovery\tFinish\n";

    for (int i = 0; i < V; i++)
    {
        cout << i << "\t";

        if (parent[i] == -1)
            cout << "NIL\t";
        else
            cout << parent[i] << "\t";

        cout << d[i] << "\t\t" << f[i] << endl;
    }
}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<int> adj[V];

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected graph
    }

    DFS(V, adj);

    return 0;
}



