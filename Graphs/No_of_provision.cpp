#include<iostream>
#include<vector>
using namespace std;

class solution{
    private:
    void dfs(int node,vector<int> adj[],int vis[]){
        vis[node]=1;
        for(auto neighbor:adj[node]){
            if(!vis[neighbor]){
                dfs(neighbor,adj,vis);
            }
        }

    }

    public:
    int numprovision(vector<vector<int>> adj,int v){
        vector<int> adjlist[v];
        for(int i=0;i<v;i++){
            for(int j =0;j<v;j++){
                if(adj[i][j]==1 && i!=j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);

                }

            }
        }
        int vis[v]={0};
        int count=0;
        for(int i=0;i<v;i++){
            if(vis[i]!=1){
                count++;
                dfs(i,adjlist,vis);
            }
        }
        return count;
    }

};
int main(){
    vector<vector<int>> adj={{1,0,1},{0,1,0},{1,0,1}};
    int v=3;
    solution obj;
    int count=obj.numprovision(adj,v);
    cout<<"No. of Provisions are : "<<count;
    return 0;
}
