#include<bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]){
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq; // min heap storing (wt, node, parent)

    vector<int> vis(V,0);
    vector<pair<int,int>> mst;

    pq.push({0,0,-1}); // starting from node 0 with weight 0 and no parent
    int sum = 0;

    while(!pq.empty()){
        auto [wt, node, parent] = pq.top();
        pq.pop();

        if(vis[node] ==1) continue;

        vis[node]=1;
        sum+=wt;
        if (parent != -1) {
            mst.push_back({parent, node});
        }


for (const auto& edge : adj[node]) {
            int adjNode = edge[0];
            int edgeWt = edge[1];

            if (!vis[adjNode]) {
                pq.push({edgeWt, adjNode, node});
            }
        }
    }


    
    return sum;



}