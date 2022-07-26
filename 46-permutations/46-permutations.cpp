class Solution {
public:
    
    
    void solve( vector<int>  &nums, int i  , vector<vector<int>> &ans)
    {
        
        if(i==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int idx = i ; idx < nums.size() ; idx++){
            
           swap(nums[i], nums[idx]);
            solve(nums, i+1, ans);
            swap(nums[i], nums[idx]);
                     
        }
        
        
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        
    solve(nums , 0,  ans);
        
        return ans;
        
        
    }
};