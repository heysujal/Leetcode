class Solution {
public:
    
    
    int solve(int i , int n)
    {
        
        if(i==n)
            return 1;
        if(i > n)
            return 0;
        
        int one = solve(i + 1, n);
        int two = solve(i + 2, n);
        
        return one + two;
    }
    
    int solveMemo(int i , int n, vector<int> &dp)
    {
        
        if(i==n)
            return 1;
        if(i > n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
            
        
        int one = solveMemo(i + 1, n,dp);
        int two = solveMemo(i + 2, n,dp);
        
        return dp[i] = one + two;
    }
    
    int climbStairs(int n) {
        
        // return solve(0 , n);
        
        vector<int> dp(n + 1, -1);
        
        return solveMemo(0, n,dp);
        
    }
};