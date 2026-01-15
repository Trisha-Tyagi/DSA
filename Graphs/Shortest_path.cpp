#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to implement Dijkstra's Algorithm
    vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(V,1e9);
        vector<int> parent;
        for(int i=0;i<V;i++){ parent.push_back(i);}
        pq.push({0,src});
        dis[src]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if (d > dis[node]) continue;
            for(auto it:adj[node]){
                if(dis[it.first]>d+it.second){
                    dis[it.first]=d+it.second;
                    pq.push({dis[it.first],it.first});
                    parent[it.first]=node;
                }
            }
        }
        return parent;
        
    }

};

int main() {
    // Number of vertices
    int V = 5;
    int destination=3;
    // Adjacency list {neighbor, weight}
    vector<vector<pair<int,int>>> adj(V);

    // Example edges
    adj[0].push_back({1, 4});
    adj[1].push_back({0, 4});

    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});

    adj[1].push_back({2, 2});
    adj[2].push_back({1, 2});

    adj[1].push_back({3, 5});
    adj[3].push_back({1, 5});

    adj[2].push_back({3, 8});
    adj[3].push_back({2, 8});

    adj[0].push_back({4, 10});
    adj[4].push_back({0, 10});

    // Run algorithm
    Solution obj;
    vector<int> dist = obj.dijkstra(V, adj, 0);
    
    // Print shortest distances
    vector<int> path;

    while(dist[destination] != destination){
        path.push_back(destination);
        destination = dist[destination];
    }
    path.push_back(destination); // push source

    reverse(path.begin(), path.end());
    for(int node : path){
    cout << node << " ";
}
    return 0;
}