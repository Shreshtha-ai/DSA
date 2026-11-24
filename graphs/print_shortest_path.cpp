#include<bits/stdc++.h>
using namespace std;

    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[n];

        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]}); // it basically means the edge from it[0] to it[1] with weight it[2]
            adj[it[1]].push_back({it[0], it[2]}); //it basically means the edge from it[1] to it[0] with weight it[2]
        }
    


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //priority_queue to store the pair of distance and node, with the smallest distance at the top

    vector<int> dist(n+1, INT_MAX);
    vector<int> parent(n+1);

    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    dist[1] = 0;
    pq.push({0,1}); //push the source node with distance 0
    while(!pq.empty()){
        auto it = pq.top();
        int dis = it.first;
        int node = it.second;
        pq.pop();

        for(auto it: adj[node]){
            int edgeweight = it.second;
            int adjnode = it.first;

            if(dis+ edgeweight< dist[adjnode]){
                dist[adjnode] = dis + edgeweight;
                pq.push({dist[adjnode], adjnode});
                parent[adjnode] = node; 
            }
        }
    }
    if(dist[n] == INT_MAX) return {-1}; //if the distance of the last node is still INT_MAX, it means there is no path from source to destination

    vector<int> path;

    int node = n;
    while(parent[node]!=node){
        path.push_back(node);
        node = parent[node];

    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    return path;

    }

    int main(){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges;
        for(int i=0; i<m; i++){
            int u,v,w;
            cin>>u>>v>>w;
            edges.push_back({u,v,w});
        }
        vector<int> ans = shortestPath(n,m,edges);
        for(auto it: ans){
            cout<<it<<" ";
        }
    }
