#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
           
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        int r=0,c=0;
          vis[0][0] = true;
        while(true){
            int nr=r,nc=c;
            if(grid[r][c]=='L')nc--;
            else if(grid[r][c]=='R') nc++;
            else if(grid[r][c]=='U')nr--;
            else if(grid[r][c]=='D')nr++;
            if(nr<0 || nr>=n || nc<0 || nc>=m) break;
            if(vis[nr][nc]) break;
            r=nr;
            c=nc;
            vis[r][c]=true;
        } return { r,c};
    }
};
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    vector<int> ans = obj.lastVisitedCell(grid);

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}