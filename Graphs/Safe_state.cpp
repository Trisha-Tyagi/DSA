#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


class solution{
    public:
    vector<int> safe_state(int v,vector<int> adj[]){
        vector<int> safe_nodes;
        int indegree[12]={0};
        vector<int> grid[12];
        for(int i=0;i<v;i++){
            for(auto it:adj[i]){
                grid[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
         for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()){
            int n=q.front();
            q.pop();
            safe_nodes.push_back(n);
            for(auto it:grid[n]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(safe_nodes.begin(), safe_nodes.end());
        return safe_nodes;
    }
};


int main(){
    vector<int> adj[12] = {{1}, {2}, {3}, {1,2,3, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
                           {8}, {9}};
    int v=12;
    solution obj;
    vector<int> safenodes=obj.safe_state(v,adj);
    for(int i=0;i<safenodes.size();i++){
        cout<<safenodes[i]<<" ";

    }
    return 0;
}