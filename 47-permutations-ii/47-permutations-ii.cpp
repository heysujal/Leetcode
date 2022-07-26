class Solution {
public:
    
      
    void solve( vector<int>  &nums, int i  , vector<vector<int>> &ans)
    {
        
        if(i==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> m;
        for(int idx = i ; idx < nums.size() ; idx++){
            
            if(m.find(nums[idx])!=m.end())
                continue;
            m.insert(nums[idx]);
            
            
           swap(nums[i], nums[idx]);
            solve(nums, i+1, ans);
            swap(nums[i], nums[idx]);
                     
        }
        
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        
        solve(nums, 0 , ans);
        
        return ans;
    }
};