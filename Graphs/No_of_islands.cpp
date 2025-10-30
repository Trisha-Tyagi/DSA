#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
    public:
    int Island(vector<vector<int>> grid){
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    q.push({i,j});
                    vis[i][j]=1;
                    cnt++;
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        for(int row=-1;row<=1;row++){
                            for(int col=-1;col<=1;col++){
                                int nrow=x+row;
                                int ncol=y+col;
                                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]!=1){
                                    q.push({nrow,ncol});
                                    vis[nrow][ncol]=1;
                                }
                            }
                        }
                    }
                }

            }
        }
        return cnt;
    

    }

};

int main(){
    vector<vector<int>> grid={{0,1,1,0},{0,1,1,0},{0,0,1,0},{0,0,0,0},{1,1,0,1}};
    Solution obj;
    int ans=obj.Island(grid);
    cout<<"No of islands : "<<ans;
    return 0;
}
