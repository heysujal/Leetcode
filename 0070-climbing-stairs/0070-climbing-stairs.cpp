class Solution {
public:
    
    
    int solve(int i)
    {
        
        if(i == 0)
            return 1;
        
        int one = 0;
        if(i-1>=0)
            one = solve(i - 1);
        int two = 0;
        if(i-2 >= 0)
            two = solve(i-2);
        
        return one + two;
        
        
    }
    
    int solveMemo(int i, vector<int> &dp)
    {
        
        if(i == 0)
            return 1;
        if(dp[i] != -1)
            return dp[i];
        
        int one = 0;
        if(i-1 >= 0)
            one = solveMemo(i - 1, dp);
        int two = 0;
        if(i-2 >= 0)
            two = solveMemo(i-2, dp);
        
        return dp[i] = one + two;
        
        
    }
    
    
      
    int solveTab(int n) {
        
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n ; i++)
        {
            int one = dp[i-1];
            int two = dp[i-2];
            dp[i] = one + two;
        }
        
        
        return dp[n];
    }
    
    
    
    int climbStairs(int n) {
        
        // return solve(n);
        // vector<int> dp(n + 1 , -1);
        // return solveMemo(n, dp);
        
        return solveTab(n);
        
    }
};