class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        for(auto &x:nums)
            x = x*x;
        int n = nums.size();
        vector<int> ans(n, 0);
        
        int i =0; 
        int j = n - 1;
        int k = n-1;
        
        while( i <= j)
        {
            
            if( nums[i] >= nums[j])
            {
                ans[k] = nums[i];
                k--;
                i++;
                
                
            }
            else{
                ans[k] = nums[j];
                j--;
                k--;
            }
            
            
            
        }
        return ans;
        
    }
};