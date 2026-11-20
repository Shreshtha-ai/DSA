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

            

        



}