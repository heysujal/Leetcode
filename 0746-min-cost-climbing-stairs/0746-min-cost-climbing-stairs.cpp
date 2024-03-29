class Solution {
public:
    
    int solve(int i, vector<int>& cost)
    {
        int n = cost.size();
        if(i == n)
            return 0;
        if(i > n)
            return 1e9;
        
        int jump1 = cost[i] + solve(i+1, cost);
        
       
        int jump2 = cost[i] + solve(i+2, cost);
        
        return min(jump1, jump2);
    }
    
    
    int solveMemo(int i, vector<int>& cost, vector<int> &dp)
    {
        int n = cost.size();
        if(i == n)
            return 0;

        if(i > n)
            return 1e9;
        if(dp[i] != -1)
            return dp[i];
        
        int jump1 = cost[i] + solveMemo(i+1, cost, dp);
        
       
        int jump2 = cost[i] + solveMemo(i+2, cost, dp);
        
        return dp[i] = min(jump1, jump2);
    }
    
    
int solveTab(vector<int>& cost, int start) {
        int n = cost.size();
    
        
        // dp[i] would represent i.....n tak ka answer
        vector<int> dp(n+1,0);
        dp[n-1] = cost[n-1];
    
        for(int i = n-2; i>= start; i--)
        {
            
            int jump1 = cost[i] + dp[i+1];
            int jump2 = cost[i] + dp[i+2];
            
            dp[i] = min(jump1, jump2);
            
            
        }
        
    return dp[start];
    }int solveSpace(vector<int>& cost, int start) {
        int n = cost.size();
        int f = cost[n-1];
        int s = 0;
    
        for(int i = n-2; i>= start; i--)
        {
            
            int jump1 = cost[i] + f;
            int jump2 = cost[i] + s;
            
            int sum  = min(jump1, jump2);
            s = f;
            f = sum;
            
            
        }
        
    return f;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // int n = cost.size();
        // return min(solve(0, cost), solve(1, cost));
        
        // dp[i] would represent i.....n tak ka answer
        
        // vector<int> dp(n+1, -1);
        // return min(solveMemo(0, cost, dp), solveMemo(1, cost, dp));
        
        // start is the starting step
        // return min(solveTab(cost, 0), solveTab(cost, 1));
        return min(solveSpace(cost, 0), solveSpace(cost, 1));
        
    }
};