class Solution {
public:
    
     int solve(int i , int j , vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        
        
        if(i >= n or j >= n or j < 0 )
        {
            return INT_MAX;
            
        }  
        
        if(i==n-1)
        {
            return matrix[i][j];
            
        }
        
        int ans = INT_MAX;
        for(int k = 0;  k < n ; k++)
        {
            
            if(j!=k)
                {
                
                
                ans = min(ans ,solve(i+1, k ,matrix));
                }
            
        }
       
        
        return matrix[i][j] + ans;
        
        
        
        
    }
    
    
      int solveMemo(int i , int j , vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        int n = matrix.size();
        
        
        if(i >= n or j >= n or j < 0 )
        {
            return INT_MAX;
            
        }  
        
        if(i==n-1)
        {
            return matrix[i][j];
            
        }
          
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans = INT_MAX;
        for(int k = 0;  k < n ; k++)
        {
            
            if(j!=k)
                {
                
                
                ans = min(ans ,solveMemo(i+1, k ,matrix, dp));
                }
            
        }
       
        
        return dp[i][j] = matrix[i][j] + ans;
        
        
        
        
    }
    
    
    int solveTab(vector<vector<int>>& grid)
    {
        int n = grid.size();
        // dp[i][j] stores the answer for [i][j] to last row minimum path sum
        vector<vector<int>> dp(n , vector<int>(n, 1e9));
        
        // filling up last row of dp
        for(int i = 0; i < n ; i++)
            dp[n-1][i] = grid[n-1][i];
        
        
         for(int i = n-2 ; i>=0; i--)
        {
            
            for(int j = n-1; j>=0; j--)
            {
                int ans = INT_MAX;
            for(int k = 0;  k < n ; k++)
            {
            
                if(j!=k)
                {
                    ans = min(ans ,dp[i+1][k]);
                }
            
            }
                
                 
        
                dp[i][j] = grid[i][j] + ans;
        
                
            }
            
            
        }
        
        
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++)
            ans = min(ans, dp[0][i]);
            
       return ans; 
      
        
        
        
        
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
         
        // int ans = INT_MAX;
      
        // for(int col = 0; col < n ; col++)
        // {
           // Recursion
            // int curr = solve(0 , col, grid);
            
            
            // Memoization
            // vector<vector<int>> dp(n , vector<int>(n, -1));
            // int curr = solveMemo(0 , col, grid, dp);
            // ans = min(ans , curr);
            
          
        // }
        
        // return ans;
        
        
        
        return solveTab(grid);
        
    }
};