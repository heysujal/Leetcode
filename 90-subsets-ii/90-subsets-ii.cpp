class Solution {
public:
    
   void  solve(vector<int> &nums, int i, vector<int> &subset, vector<vector<int>>&ans )
        
    {
        if(i == nums.size() )
        {
            ans.push_back(subset);
            return;
            
            
        }
       
       
       //pick
       subset.push_back(nums[i]);
       solve(nums,  i+1, subset, ans);
       subset.pop_back();
       
       // skip
       while(i+1 < nums.size() and nums[i]==nums[i+1])
           i++;
       solve(nums, i+1, subset, ans);
        
        
        
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        
        vector<int> subset;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(nums , 0 , subset, ans);
        return ans;
        
    }
};