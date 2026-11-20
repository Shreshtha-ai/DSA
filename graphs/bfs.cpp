#include<bits/stdc++.h>
using namespace std;

void bfs(int V, vector<int> adj[], int start){
        vector<string> color(V, "WHITE");
        vector<int> distance(V, INT_MAX);
        vector<int> parent(V, -1);

        color[start] = "GRAY";
        distance[start] = 0;
        parent[start] = -1;

        queue<int> Q;
        Q.push(start);

        while (!Q.empty()){
            int u = Q.front();
            Q.pop();

            for(int v : adj[u]){
                if(color[v] =="WHITE"){
                    color[v] = "GRAY";
                    distance[v] = distance[u] + 1;
                    parent[v] = u;
                    Q.push(v);
                }
            }

            color[u] = "BLACK";

        }




cout << "\nVertex\tDistance\tParent\n";

    for (int i = 0; i < V; i++)
    {
        cout << i << "\t" << distance[i] << "\t\t";

        if (parent[i] == -1)
            cout << "NIL";
        else
            cout << parent[i];

        cout << endl;
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

    int s;
    cout << "Enter source vertex: ";
    cin >> s;

    bfs(V, adj, s);

    return 0;
}
