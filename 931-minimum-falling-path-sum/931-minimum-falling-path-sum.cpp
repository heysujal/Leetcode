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
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        for(int col = 0; col < n ; col++)
        {
            
            // int curr = solve(0 , col, matrix);
            vector<vector<int>> dp(n , vector<int>(n , -1));
            int curr = solveMemo(0 , col, matrix, dp);
            
            ans = min(ans, curr);
            
            
        }
        return ans;
    }
};