#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class solution{
    public:
    int orange_rotten(vector<vector<int>> grid){
        int n=grid.size();//no of rows
        int m=grid[0].size();//no of columns
        int vis[n][m];
        queue<pair<pair<int,int>,int>> q;
        int fresh=0;
        int fresh_orange=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    if(grid[i][j]==1) fresh+=1;
                    vis[i][j]=0;
                }
            }
        }

        int tm=0;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int t=q.front().second;
            tm=max(t,tm);
            q.pop();
            int row[]={0,0,-1,1};
            int col[]={-1,1,0,0};
            for(int i=0;i<4;i++){
                int nrow=x+row[i];
                int ncol=y+col[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]!=1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=1;
                    fresh_orange+=1;
                }

            }
        }
        if (fresh!=fresh_orange)
        {
            return -1;
        }
        return tm;
    }
};

int main(){
    vector<vector<int>> grid={{1,0,0},{0,2,1},{0,0,1}};
    solution obj;
    int time=obj.orange_rotten(grid);
    cout<<"Time taken : "<<time;
    return 0;
}