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
        
        int d =   solve(i+1, j , matrix);
        int dr =  solve(i+1, j+1 , matrix);
        int dl =  solve(i+1, j-1 , matrix);
        
        return matrix[i][j] + min(d, min(dr, dl));
        
        
        
        
    }
    
    int solveMemo(int i , int j , vector<vector<int>>& matrix, vector<vector<int>> &dp)
    {
        int n = matrix.size();
        
        
        if(i >= n or j >= n or j < 0 )
        {
            return INT_MAX;
            
        }  
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
            
        }
        
        if(i==n-1)
        {
            return matrix[i][j];
            
        }
        
        int d =   solveMemo(i+1, j , matrix, dp);
        int dr =  solveMemo(i+1, j+1 , matrix, dp);
        int dl =  solveMemo(i+1, j-1 , matrix, dp);
        
        return dp[i][j] = matrix[i][j] + min(d, min(dr, dl));
        
        
        
        
    }
    
    
    int solveTab(vector<vector<int>>& matrix)
    {
        int n  = matrix.size();
        
        // dp[i][j] stores answer for [i][j] to last row minimum path sum
        
        vector<vector<int>> dp(n , vector<int>(n , 0));
        
        
        for(int j = 0; j < n ; j++)
            dp[n-1][j] = matrix[n-1][j];
        
        
        for(int i = n-2 ; i>=0; i--)
        {
            
            for(int j = n-1; j>=0; j--)
            {
                int d =  INT_MAX;
                int dr = INT_MAX;
                int dl = INT_MAX;
                
                if(i+1 <= n-1) 
                    d  =  dp[i+1][j];
                
                if(i+1 <= n-1 and j+1 <= n-1)
                    dr =  dp[i+1][j+1];
                
                if(i+1 <= n-1 and j-1>=0)
                    dl =  dp[i+1][j-1];
        
                dp[i][j] = matrix[i][j] + min(d, min(dr, dl));
        
                
            }
            
            
        }
        
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++)
            ans = min(ans, dp[0][i]);
            
       return ans; 
    }
    
    int solveSpace(vector<vector<int>>& matrix)
        
    {
        
        int n  = matrix.size();
        
        // dummy stores for lower row 
        // curr stores for current row
        
        vector<int> dummy(n ,0);
        vector<int> curr(n, 0);
        
        
        for(int j = 0; j < n ; j++)
            dummy[j] = matrix[n-1][j];
        
        
        for(int i = n-2 ; i>=0; i--)
        {
            
            for(int j = n-1; j>=0; j--)
            {
                int d =  INT_MAX;
                int dr = INT_MAX;
                int dl = INT_MAX;
                
                if(i+1 <= n-1) 
                    d  =  dummy[j];
                
                if(i+1 <= n-1 and j+1 <= n-1)
                    dr =  dummy[j+1];
                
                if(i+1 <= n-1 and j-1>=0)
                    dl =  dummy[j-1];
        
                curr[j] = matrix[i][j] + min(d, min(dr, dl));
        
                
            }
            
            dummy = curr;
        }
        
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++)
            ans = min(ans, dummy[i]);
            
       return ans; 
        
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        // int n = matrix.size();
        // int ans = INT_MAX;
        // for(int col = 0; col < n ; col++)
        // {
           //// Recursion
            // int curr = solve(0 , col, matrix);
        
             //// Memoization
//             vector<vector<int>> dp(n , vector<int>(n , -1));
//             int curr = solveMemo(0 , col, matrix, dp);
            
//             ans = min(ans, curr);
            
            
        // }
        // return ans;
        
        // return solveTab(matrix);
        
        return solveSpace(matrix);
    
    }
};