class Solution {
public:
    // this question is same as partion difference D problem
    // S1-S2 = D
    
      
    int solve(int i , vector<int>& nums, int target)
    {
        
        if(i == 0)
        {
            if(target == 0 and nums[0]==0)
                return 2;
            
            if(target == 0 and nums[0] != 0)
                return 1;
            
            if(target != 0 and  target - nums[i] == 0 )
                return 1;
            else
                return 0;
                
                    
        }
        
        int pick = 0;
        
        if(target - nums[i] >= 0)
            pick = solve(i-1, nums, target - nums[i]);
        
        int skip = solve(i-1, nums, target);        
        return pick + skip;
    }
    
    
    int solveMemo(int i , vector<int>& nums, int target, vector<vector<int>> &dp)
    {
        
        if(i == 0)
        {
            if(target == 0 and nums[0]==0)
                return 2;
            
            if(target == 0 and nums[0] != 0)
                return 1;
            
            if(target != 0 and  target - nums[i] == 0 )
                return 1;
            else
                return 0;
                
                    
        }
        
        if(dp[i][target] != -1)
            return dp[i][target];
        
        int pick = 0;
        
        if(target - nums[i] >= 0)
            pick = solve(i-1, nums, target - nums[i]);
        
        int skip = solve(i-1, nums, target);        
        return dp[i][target] = pick + skip;
    }
    
    
    int solveTab(vector<int>& nums, int d, int target) {
  
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (target + 1, 0));
        
        // filling base case
        
        if(nums[0] == 0)
           dp[0][0] = 2;
        else
           dp[0][0] = 1;
        
        if(nums[0] != 0 and nums[0] <= target)
           dp[0][nums[0]] = 1;
        
        
        
        for(int i = 1; i < n ; i++)
        {
            
            for(int j = 0 ; j <= target; j++)
            {
                
                int pick = 0;
                
                if(j - nums[i] >= 0)
                    pick = dp[i-1][j-nums[i]];
        
                int skip = dp[i-1][j];  
                
                dp[i][j] = pick + skip;
                
                
            }
            
        }
        
        
        return dp[n-1][target];        
    }
    
    
    int solveSpace(vector<int>& nums, int d, int target) {
  
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (target + 1, 0));
        vector<int> prev(target+1,0), next(target + 1, 0);
        // filling base case
        
        if(nums[0] == 0)
           prev[0] = 2;
        else
           prev[0] = 1;
        
        if(nums[0] != 0 and nums[0] <= target)
           prev[nums[0]] = 1;
        
        
        
        for(int i = 1; i < n ; i++)
        {
            
            for(int j = 0 ; j <= target; j++)
            {
                
                int pick = 0;
                if(j - nums[i] >= 0)
                    pick = prev[j-nums[i]];
        
                int skip = prev[j];  
                
               next[j] = pick + skip;
                
                
            }
            
            prev = next;
            
        }
        
        
        return prev[target];        
    }
    
    
    int findTargetSumWays(vector<int>& nums, int d) {
        
        // s1+s2=sum;
        // sum-s2 = s1;       
        // s1-s2 = d;
        // sum-2s2 = d
        // s2 = (sum - d)/2;
        
        // check if how many subsets exists such that their sum is           // (sum-d)/2 
        int n = nums.size();
        int sum = 0;
        for(auto x:nums)
            sum+=x;
        if(sum - d < 0 or (sum-d)%2 != 0)
            return 0;
        
        int target = (sum - d)/2;
        
        // return solve(n-1, nums, target);
        vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        
        // return solveMemo(n-1, nums, target, dp);
        
        // return solveTab(nums , d, target);
        return solveSpace(nums , d, target);
        
        
    }
};