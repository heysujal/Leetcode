//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int m;
    int n;
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &v, vector<vector<int>> &grid, int x0, int y0){
        if(i < 0 or j < 0 or i >= m or j >= n or grid[i][j] != 1)
            return;
        // vis[i][j] = true;
        grid[i][j] = 2;
        v.push_back({i-x0, j-y0});
        dfs(i-1,j,vis,v,grid,x0,y0);
        dfs(i+1,j,vis,v,grid,x0,y0);
        dfs(i,j-1,vis,v,grid,x0,y0);
        dfs(i,j+1,vis,v,grid,x0,y0);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        set<vector<vector<int>>> st;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 2){
                    if(grid[i][j] == 1){
                        vector<vector<int>> v;
                        dfs(i,j,vis,v,grid,i,j);
                        st.insert(v);
                    }
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends