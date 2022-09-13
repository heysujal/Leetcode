class Solution {
public:
    // Memoization
    
    // solve is a function which gives answer of going 
//         [i-1][j-1] to [0][0]
    
    int solveMemo(int i , int j, vector<vector<int>> &dp)
    {
        if(i<0 or j <0)
            return 0;
        if(i==0 and j==0)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int up = solveMemo(i-1,j, dp);
        int left = solveMemo(i , j-1, dp);
        
        return dp[i][j] = up + left;
        
        
        
    }
    
    
    
    int solveTab(int m , int n)
    {
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
         
        
        
        for(int i = 0; i < m ; i++)
        {
            
            
            for(int j = 0;  j < n ; j++)
            {
                
                if(i==0 and j==0) dp[i][j] = 1;
                
                else
                {
                    int up = 0;
                    int left = 0;
                    
                    if(i>0)
                        up = dp[i-1][j];
                    if(j>0)
                        left = dp[i][j-1];
                    
                    dp[i][j] = up + left;
                }
                
                
            }
        }
        
        
        
        return dp[m-1][n-1];
        
    }
    
    
    
    
    
    
    
    
    int uniquePaths(int m, int n) {
            // vector<vector<int>> dp(m, vector<int>(n, -1));
            // return solveMemo(m-1, n-1, dp);
        
        
        
        // tabulation
        return solveTab(m, n);
        
        
    }
};