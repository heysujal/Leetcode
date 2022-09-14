class Solution {
public:
    
//     void solve(int i, int j ,vector<vector<int>>& grid, int m , int n, int &ans , int sum)
//     {
        
//         if(i >= m or j >= n)
//         {
//             return;
//         }
        
//         if(i==m-1 and j==n-1)
//         {
            
//             ans = min(ans, sum);
//             return;
//         }
        
        
//          solve(i, j+1, grid, m, n , ans, sum + grid[i][j]);
//          solve(i+1, j , grid, m, n , ans , sum + grid[i][j]);
     
//     }
    
    
    
     int solve(int i, int j ,vector<vector<int>>& grid, int m , int n,int sum)
    {
        
        if(i >= m or j >= n)
        {
            return INT_MAX;
        }
        
        if(i==m-1 and j==n-1)
        {
            
            return sum + grid[i][j];
        }
        
        
         int right = solve(i, j+1, grid, m, n ,sum + grid[i][j]);
         int down = solve(i+1, j , grid, m, n , sum + grid[i][j]);
         
         
         return min(right, down);
     
    }
    
    int solveMemo(int i, int j ,vector<vector<int>>& grid, int m , int n, vector<vector<int>> &dp)
    {
        
        if(i >= m or j >= n)
        {
            return INT_MAX;
        }
        
            
        
        if(i==m-1 and j==n-1)
        {
            
            return grid[i][j];
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
         int right = solveMemo(i, j+1, grid, m, n, dp);
         int down = solveMemo(i+1, j , grid, m, n, dp);
         
         
         return dp[i][j] = grid[i][j] + min(right, down);
     
    }
    
    
    
    int minPathSum(vector<vector<int>>& grid) {
        // int ans = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        
        // return solve(0, 0 , grid, m, n, 0);
        
        vector<vector<int>> dp(m , vector<int>(n, -1));
        
        return solveMemo(0 , 0 , grid, m , n ,dp);
         
        
    }
};