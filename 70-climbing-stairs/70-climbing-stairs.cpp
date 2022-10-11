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
    
    int solveTab(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[n]  = 1;
        
        
         
       for(int i = n-1 ; i >= 0; i--)
       {
           
           int one = dp[i+1];
           
           int two = 0;
           
           if(i+2 <= n)
               two = dp[i+2];
           
           dp[i] = one + two;
           
       }
        
        
        
        return dp[0] ;
    }
    
    
    int solveSpace(int n)
    {
        int one = 1; // for n 
        int two = 0; // for beyond n
          
       for(int i = n-1 ; i >= 0; i--)
       {     
           int ans = one + two;
           two = one;
           one = ans;
       }
        
        return one;
    }
    
    
    
    
    int climbStairs(int n) {
        
        // return solve(0 , n);
        
        // vector<int> dp(n + 1, -1);
        
        // return solveMemo(0, n,dp);
        
        
        // return solveTab(n);
        return solveSpace(n);
        
    }
};