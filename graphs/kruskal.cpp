#include<bits/stdc++.h>
using namespace std;


class DisjointSet {
    vector<int> rank, parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
            parent[i]=i;

        }

    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){ // TC = O(4*alpha) ~ O(1) alpha = inverse Ackermann function
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // union by size
    void unionBySize(int u, int v){ // TC = O(4*alpha) ~ O(1) alpha = inverse Ackermann function
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(size[ulp_v]<size[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};


int kruskal(int V, vector<vector<int>> adj[]){
    vector<pair<int,pair<int,int>>> edges; // {wt,{u,v}}

    for(int i=0;i<V;i++){
        for(auto it: adj[i]){
            int adjnode = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt,{node,adjnode}});
        }
    }
    DisjointSet ds(V);

    sort(edges.begin(),edges.end());
    int mstwt = 0;

    for(auto it: edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        // check if u and v belong to same component or not
        // if they belong to same component then ignore the edge
        // otherwise take the edge in mst

        if(ds.findUPar(u) != ds.findUPar(v)){
            mstwt += wt;
            ds.unionBySize(u,v);
        }
    }

    return mstwt;

}
