#include<iostream>
#include<set>
#include<vector>
using namespace std;
class solution{
    private:
    void dfs(vector<vector<int>> & grid,vector<pair<int,int>> & vec,vector<vector<int>> &vis,int row,int col,int row0,int col0,int n,int m){
        int row_index[4]={0,0,-1,1};
        int col_index[4]={-1,1,0,0};
        vis[row][col]=1;
        vec.push_back({row-row0,col-col0});
        for(int i=0;i<4;i++){
            int nrow=row+row_index[i];
            int ncol=col+col_index[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(grid,vec,vis,nrow,ncol,row0,col0,n,m);
            }

        }

    }
    public:
    int count_islands(vector<vector<int>> & grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(grid,vec,vis,i,j,i,j,n,m);
                    result.insert(vec);
                }

            }

        }
        return result.size();
    }

};
int main(){
    vector<vector<int>> grid={{1,1,0,0,1},{1,0,0,0,1},{1,1,0,0,0}};
    solution s;
    int n=s.count_islands(grid);
    cout<<"No of Distinct islands: "<<n;
    return 0;
}