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
    
     bool solveTab(vector<int>& nums) {
        
        int n = nums.size();
        // return solve(0, nums);
        
        vector<int> dp(n, 0);
        
        dp[n-1] = true;
        
        for(int i = n-2 ; i>=0 ; i--)
        {
           
            for(int jump = 1 ; jump <= nums[i] ; jump++)
            {

                if(i+jump < n and dp[i+jump])
                     { 
                        dp[i] = true;
                        break;
                     }

            }
            
            
        }
         
        
        return dp[0];
        
    }
    
    bool solveSpace(vector<int>& nums) {
        
        int n = nums.size();
        int last = n-1;
        
        for(int i = n-2 ; i >= 0; i--)
        {
            
            if( i + nums[i] >= last)
                last = i;
            
            
            
        }
        
        
        return last==0;
       
    }
  
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        // return solve(0, nums);
        
        // vector<int> dp(n, -1);
        // return solveMemo(0, nums, dp);
        
        // return solveTab(nums);
           return solveSpace(nums);
        
    }
};