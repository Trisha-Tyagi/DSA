#include <bits/stdc++.h>
using namespace std;
class solution{
    public:
    void dfs(int node,vector<int> adj[],int vis[],vector<int> &ls){
        vis[node]=1;
        ls.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,ls);
            }
        }
    }

    vector<int> dfsofgraph(int V,vector<int> adj[]){
        int vis[V]={0};
        int start=0;
        vector<int> ls;
        dfs(start,adj,vis,ls);
        return ls;
    }
};

void add(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printans(vector<int> ans){
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main(){
    vector <int> adj[5];
    
    add(adj, 0, 1);
    add(adj, 1, 2);
    add(adj, 1, 3);
    add(adj, 0, 4);

    solution obj;
    vector<int> ans=obj.dfsofgraph(5,adj);
    printans(ans);
    return 0;


}