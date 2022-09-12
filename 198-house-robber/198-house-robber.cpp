class Solution {
public:
    
    
    
     
    
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n+1, 0);
       
        // I am solving as [0...index]
        
        // base case
        
        dp[0] = nums[0];
        
      for(int i = 1; i < n ; i++)
      {
          
          int pick = nums[i] ;
          if(i>1)
              pick += dp[i-2];
        
          int skip  = dp[i-1];
        
          dp[i] = max(pick , skip);
     
          
          
      }
        
        return dp[n-1];
        
    }
};