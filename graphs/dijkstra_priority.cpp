#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //priority_queue to store the pair of distance and node, with the smallest distance at the top

    vector<int> dist(V, INT_MAX);
    dist[S]= 0;

    pq.push({0,S});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;

        pq.pop();
        for(auto it: adj[node]){
            int edgeweight = it[1];
            int adjnode = it[0];

            if(dis+edgeweight<dist[adjnode]){
                dist[adjnode] = dis + edgeweight;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }
    return dist;
}