class Solution {
public:
    // there are duplicates in nums
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
     
        int temp = i;
        
        //skip element
        while(i+1 < nums.size() and nums[i]==nums[i+1])
            i++;
        
        help(i+1, nums  , sumtillnow,target , subset, ans);
        
        i = temp;
        
        // pick element
        subset.push_back(nums[i]);
        sumtillnow += nums[i];
        help(i+1,nums ,sumtillnow , target , subset, ans );
        sumtillnow -= nums[i];
        subset.pop_back();
        
            
        
        
        
    }
    
    
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        vector<int> subset;
        int sumtillnow = 0;
        
        sort(nums.begin(), nums.end());
        
        
        help(0 ,nums, sumtillnow,target,    subset , ans );
        
        
        return ans;
        
    }
};