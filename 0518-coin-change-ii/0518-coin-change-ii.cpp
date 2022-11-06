class Solution {
public:
    
    
    int solve(int i , int target, vector<int>& coins )
    {
        
        if(i==0)
        {
             if(target % coins[i] == 0)
                return 1;
             else         
                return 0;
        }
        
        
        
        int skip = solve(i-1, target, coins);
        
        int pick = 0;
        
        if(target - coins[i] >= 0)
                pick = solve(i, target - coins[i], coins);
        
        return pick + skip;
        
    }
    
    int solveMemo(int i , int target, vector<int>& coins 
                 ,  vector<vector<int>> &dp)
    {
        
        if(i==0)
        {
             if(target % coins[i] == 0)
                return 1;
             else         
                return 0;
        }
        
        if(dp[i][target] != -1)
            return dp[i][target];
        
        
        
        int skip = solve(i-1, target, coins);
        
        int pick = 0;
        
        if(target - coins[i] >= 0)
                pick = solve(i, target - coins[i], coins);
        
        return dp[i][target] = pick + skip;
        
    }
    
     int solveTab(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        // return solve(n-1, amount, coins);
        vector<vector<int>> dp(n , vector<int>(amount+1 , 0));
         
        for(int target = 0 ; target <= amount; target++)
        {
            dp[0][target] = (target % coins[0] == 0);
            
        }
         
         
        for(int i = 1; i < n ; i++)
        {
            
            for(int target = 0 ; target <= amount ; target++)
            {
                
                int skip = dp[i-1][target];
                int pick = 0;
                
                if(target - coins[i] >= 0)
                    pick =   dp[i][target - coins[i]];
                
                dp[i][target] = skip + pick;
                
                
            }
            
            
        }
        
       return dp[n-1][amount];  
        
        
    }
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        // return solve(n-1, amount, coins);
        // vector<vector<int>> dp(n , vector<int>(amount+1 , -1));
        // return solveMemo(n-1, amount, coins, dp);
        
        return solveTab(amount, coins);
        
    }
};