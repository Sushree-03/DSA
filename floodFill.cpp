#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void dfs(int sr, int sc, vector<vector<int>>& image , int color, int old){
    int n=image.size();
    int m=image[0].size();
    if(sr<0 || sc<0 || sr>=n || sc>=m)
    return;
    if(image[sr][sc]!=old) return;
    image[sr][sc]=color;
    dfs(sr+1,sc,image,color,old);
     dfs(sr-1,sc,image,color,old);
      dfs(sr,sc-1,image,color,old);
       dfs(sr,sc+1,image,color,old);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old=image[sr][sc];
        if(old==color) return image;
        dfs(sr,sc,image,color,old);
        return image;
    }
};
int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
 
    int sr = 1;
    int sc = 1;
    int color = 2;
 
    Solution sol;
 
    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);
 
    // Print the updated image.
    for (vector<int>& row : result) {
        for (int value : row) {
            cout << value << " ";
        }
 
        cout << "\n";
    }
 
    return 0;
}