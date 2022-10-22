class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int zeroInd = -1;
        int prod = 1;
        int zeroCount = 0;
        vector<int> ans(nums.size(), 0);
        
        for(int i = 0; i < nums.size() ; i++)
        {

              if(nums[i]!=0)
                prod = prod * nums[i];      
            
              else
                {
                  zeroCount++;
                  zeroInd = i;
                  if(zeroCount > 1)
                    break;
                  
                  
                }
        
        }
        
        if(zeroCount > 1)
            return ans;
        
        if(zeroCount == 0)
        {
            
            for(int i =0; i < nums.size(); i++)
            {
                ans[i] = prod / nums[i];                
            }
            
        }
        else
            ans[zeroInd] =prod;
        
        return ans;
            
        
        
    }
};