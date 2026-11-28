#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> vis[],vector<int> adj[]){
    vis[node]= 1;
    for(auto adjnode: adj[node]){
        if(!vis[adjnode]){
            if(dfs(adjnode,node,vis,adj)==true) return true;
        }
        else if(adjnode !=parent){
            return true;
        }
        
    }
    return false;
}


bool isCycle(int V, vector<int> adj[]){
    int vis[V]= {0};
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,-1,vis,adj) == true) return true;
        }
    }
    return false;
}
