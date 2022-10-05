class Solution {
public:
    
    
    // solve(i  , target) gives me the answer for 0......i
    bool solve(int i , vector<int> &nums, int target)
    {
        
        if(target==0)
            return true;
        if(target < 0)
            return false;
        
        if(i == 0)
            return (target == nums[0]);
        
        //pick
        
        bool op1 = solve(i-1, nums, target - nums[i]);
        
        //skip
        bool op2 = solve(i-1, nums, target);
        
        return op1 or op2;
        
    }
    
    
      
    bool solveMemo(int i , vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        
        if(target==0)
            return true;
        
        if(target < 0)
            return false;
        
        if(dp[i][target] != -1)
            return dp[i][target];
        
        if(i == 0)
            return (target == nums[0]);
        
        //pick
        
        bool op1 = solveMemo(i-1, nums, target - nums[i], dp);
        
        //skip
        bool op2 = solveMemo(i-1, nums, target, dp);
        
        return dp[i][target] = op1 or op2;
        
    }
    
    
    bool solveTab(vector<int>& nums , int target)
    {
        int  n = nums.size();
       
        
        vector<vector<int>> dp(n , vector<int>(target+1, 0)); 
        
        // first base case
        
        for(int i =0 ; i < n ; i++)
            dp[i][0] = true;
        
        if(nums[0] == target) // Why nums[0] == target doesn't work ?
            dp[0][nums[0]] = true;
        
        
        for(int i = 1 ; i < n; i++)
        {
            
            for(int j = 0; j <= target; j++)
            {
            
                bool op1 = false;
                if(j >= nums[i])
                    op1 = dp[i-1][j - nums[i]];
                bool op2 = dp[i-1][j];
                
                dp[i][j] = op1 or op2;
                
            }
            
        }
            
            
        return dp[n-1][target];
    }
    
    
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(auto x: nums)
            sum+=x;
        if(sum%2!=0)
            return false;
        
        int target = sum / 2;
        
        int n = nums.size();
        
        // return solve(n-1 , nums, target);
        
        
        // vector<vector<int>> dp(n , vector<int>(target+1, -1));
        // return solveMemo(n-1, nums, target, dp);
        
    return solveTab(nums, target);
        
    }
};