#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   void dfs(int i,vector<vector<int>>& isConnected, vector<int>& visited){
    visited[i]==1;
    int n=isConnected.size();
    for(int j=0;j<n;j++){
        if(isConnected[i][j]==1 && visited[j]==0){
            dfs(j,isConnected,visited);
        }
    }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                count++;
                dfs(i,isConnected,visited);
            }
        } return count;
    }
};
int main() {
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
 
    Solution sol;
 
    cout << sol.findCircleNum(isConnected);
 
    return 0;
}