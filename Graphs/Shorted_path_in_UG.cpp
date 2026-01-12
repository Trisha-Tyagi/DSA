#include <iostream>
#include<vector>
#include<queue>
using namespace std;
// each edge has unit weight
class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<int> adj[N];
        
        for(auto it:edges){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int dist[N];
        for (int i = 0; i < N; i++) 
            dist[i] = 1e9;
        dist[src]=0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                
                if(dist[it]>dist[node]+1){
                    dist[it]=dist[node]+1;
                    q.push(it);
                    // If we already updated the distance of a node, why do we still need to push it into the queue?
                    // Because updating the distance only fixes that node — pushing it into the queue allows that node to fix others.
                }
            }
        }
         // Initialize the result array with -1 for unreachable nodes
        vector<int> ans(N, -1);

        // Fill in the result array with distances where reachable
        for (int i = 0; i < N; i++) {
            if (dist[i] != 1e9) {
                ans[i] = dist[i]; 
            }
        }

        // Return the final shortest distances
        return ans; 


        

    }
};

int main() {

    // Number of vertices and edges
    int N = 9, M = 10;

    // Edge list representing the undirected graph
    vector<vector<int>> edges = {
        {0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6},
        {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}
    };

    // Create object of Solution class
    Solution obj;

    // Call the shortestPath function with source as node 0
    vector<int> ans = obj.shortestPath(edges, N, M, 0);

    // Print the shortest distances from source to each node
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}