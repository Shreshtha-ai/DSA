#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<int>> adj[], int S){

    set<pair<int,int>> st; //set to store the pair of distance and node, with the smallest distance at the top

    vector<int> dist(n, INT_MAX);
    dist[S] = 0;

    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;

        st.erase(it);
        for(auto it: adj[node ]){
            int edgeweight = it[1];
            int adjnode = it[0];
            if(dis + edgeweight < dist[adjnode]){
                if(dist[adjnode] != INT_MAX){
                    st.erase({dist[adjnode], adjnode});
                }
                dist[adjnode] = dis + edgeweight;
                st.insert({dist[adjnode], adjnode});
            }
        }
        
    }
    return dist;
}