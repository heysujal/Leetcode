class Solution {
public:
    
    
    
    
    // lets solve dp from [0...index]
    
    int solve(int i, vector<int> &nums, vector<int>&dp)
    {
        
        if(i==0)
        {
            return nums[0];
        }
        
        if ( i < 0)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        
        int pick = nums[i] + solve(i-2, nums, dp);
        
        int skip  = solve(i-1, nums, dp);
        
        return dp[i] = max(pick , skip);
     
    }
    
    
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, -1);
        
        // get answer of 0...n-1
       return solve(n-1, nums, dp);
        
        
        
    }
};