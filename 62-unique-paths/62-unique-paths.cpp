class Solution {
public:
    // Memoization
    
    // solve is a function which gives answer of going 
//         [i-1][j-1] to [0][0]
    
    int solve(int i , int j, vector<vector<int>> &dp)
    {
        if(i<0 or j <0)
            return 0;
        if(i==0 and j==0)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int up = solve(i-1,j, dp);
        int left = solve(i , j-1, dp);
        
        return dp[i][j] = up + left;
        
        
        
    }
    
    
    
    int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m, vector<int>(n, -1));
            return solve(m-1, n-1, dp);
    }
};