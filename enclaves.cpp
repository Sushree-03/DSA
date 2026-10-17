#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
     queue<pair<int,int>>q;
     int n=grid.size();
     int m= grid[0].size();
     vector<vector<int>>vis(n, vector<int>(m,0));  
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0 || i==n-1 || j==m-1 ){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
      } int drow[]={-1,0,1,0};
      int dcol[]={0,1,0,-1};
      while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
            }
        }
      } int c=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && vis[i][j]==0) c++;
        }
      } return c;
    }
};int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
 
    Solution sol;
 
    cout << sol.numEnclaves(grid);
 
    return 0;
}