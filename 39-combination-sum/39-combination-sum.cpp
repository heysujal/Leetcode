class Solution {
public:
    
    void help(int i , vector<int> &nums, int &sumtillnow,int &target,  vector<int> &subset,                   vector<vector<int>> &ans)
        
    {
           if(sumtillnow == target)
        {
            ans.push_back(subset);
            return ;
            
        }
        
        if(sumtillnow > target)
            return ;
         
        if(i == nums.size())
            return ;
    
        
        //skip element
        help(i+1, nums  , sumtillnow,target , subset, ans);
        
        
        // pick element
        subset.push_back(nums[i]);
        sumtillnow += nums[i];
        help(i,nums ,sumtillnow , target , subset, ans );
        sumtillnow -= nums[i];
        subset.pop_back();
        
            
        
        
        
    }
    
    
    
    
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        vector<int> subset;
        int sumtillnow = 0;
        
        
        
        help(0 ,nums, sumtillnow,target,    subset , ans );
        
        
        return ans;
        
    }
};