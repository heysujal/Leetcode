class Solution {
public:
    
    bool solve(int i , vector<int> &nums)
    {

        int n = nums.size();
        if( i >= n-1)
            return true;
        
        
        
        for(int jump = 1 ; jump <= nums[i] ; jump++)
        {
            
            if(solve(i+jump, nums))
                return true;
            
        }
        
        return false;
    
    }
    
    
    bool solveMemo(int i , vector<int> &nums , vector<int> &dp)
    {

        int n = nums.size();
        if( i >= n-1)
            return true;
        
        if(dp[i] != -1)
            return dp[i];
        
        for(int jump = 1 ; jump <= nums[i] ; jump++)
        {
            
            if(solveMemo(i+jump, nums, dp))
                return dp[i] = true;
            
        }
        
        return dp[i] = false;
    
    }
    
    
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        // return solve(0, nums);
        
        vector<int> dp(n, -1);
        return solveMemo(0, nums, dp);
        
        
    }
};