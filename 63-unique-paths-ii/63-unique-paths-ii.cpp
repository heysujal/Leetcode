class Solution {
public:
    
    
    int solveMemo(int i , int j, vector<vector<int>> &dp,vector<vector<int>> &grid)
    {
        if(i<0 or j <0 or grid[i][j]==1)
            return 0;
        if(i==0 and j==0)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int up = solveMemo(i-1,j, dp, grid);
        int left = solveMemo(i , j-1, dp, grid);
        
        return dp[i][j] = up + left;
        
        
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return solveMemo(m-1, n-1, dp, grid);
    }
};