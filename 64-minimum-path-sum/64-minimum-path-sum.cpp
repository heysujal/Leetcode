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
    
    
    
//      int solve(int i, int j ,vector<vector<int>>& grid, int m , int n,int sum)
//     {
        
//         if(i >= m or j >= n)
//         {
//             return INT_MAX;
//         }
        
//         if(i==m-1 and j==n-1)
//         {
            
//             return sum + grid[i][j];
//         }
        
        
//          int right = solve(i, j+1, grid, m, n ,sum + grid[i][j]);
//          int down = solve(i+1, j , grid, m, n , sum + grid[i][j]);
         
         
//          return min(right, down);
     
//     }
    
//     int solveMemo(int i, int j ,vector<vector<int>>& grid, int m , int n, vector<vector<int>> &dp)
//     {
        
//         if(i >= m or j >= n)
//         {
//             return INT_MAX;
//         }
        
            
        
//         if(i==m-1 and j==n-1)
//         {
            
//             return grid[i][j];
//         }
        
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//          int right = solveMemo(i, j+1, grid, m, n, dp);
//          int down = solveMemo(i+1, j , grid, m, n, dp);
         
         
//          return dp[i][j] = grid[i][j] + min(right, down);
     
//     }
    
    int solveTab(vector<vector<int>>& grid)
        
    {
        
            int m = grid.size();
            int n = grid[0].size();
        
        
            
            vector<vector<int>> dp(m , vector<int>(n, 0 ));
            
            // dp[i][j] stores answer for going [i][j] to [m-1][n-1]
        
        dp[m-1][n-1] = grid[m-1][n-1];
        
        
        for(int i =m-1 ; i>=0 ; i--)
        {
            
            for(int j =n-1 ; j>=0 ;j-- )
            {   
                if(i==m-1 and j==n-1)
                    dp[i][j] = grid[i][j];
                
                else{
                    int right = INT_MAX;
                    int down = INT_MAX;
                
                if(i<m-1)
                    down = grid[i][j]+ dp[i+1][j];
                if(j < n-1)
                    right = grid[i][j] +dp[i][j+1];
                
                dp[i][j] =  min(down , right);
                    
                    
                    
                }
                
                
                
                
                
            }
            
        }
        
            
          return dp[0][0];  
        
        
    }
    
    
    int solveSpace(vector<vector<int>> &grid)
    {
        
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dummy(n, 0);
        
        
         for(int i =m-1 ; i>=0 ; i--)
        {
            vector<int> curr(n , 0);
             
            for(int j =n-1 ; j>=0 ;j-- )
            {   
                if(i==m-1 and j==n-1)
                   curr[j] = grid[i][j];
                
                else{
                    int right = INT_MAX;
                    int down = INT_MAX;
                
                if(i<m-1)
                    down = grid[i][j]+ dummy[j];
                if(j < n-1)
                    right = grid[i][j] + curr[j+1];
                
                curr[j] =  min(down , right);
                    
                    
                    
                }
                
                
                
                
                
            }
             
             
             dummy = curr;
            
        }
        return dummy[0];
        
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        // int ans = INT_MAX;
        // int m = grid.size();
        // int n = grid[0].size();
        
        // return solve(0, 0 , grid, m, n, 0);
        
        // vector<vector<int>> dp(m , vector<int>(n, -1));
        
        // return solveMemo(0 , 0 , grid, m , n ,dp);
        
        
        
        // return solveTab(grid);
        
        return solveSpace(grid);
         
        
    }
};