class Solution {
public:
    
    
    
    
     void perm(vector<int>& nums , vector<vector<int>> &ans , int idx)
        
    {
        
        if(idx == nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        
        
        
        for(int i = idx ; i < nums.size() ; i++)
        {
            swap(nums[i], nums[idx]);
            perm(nums, ans, idx+1);
            swap(nums[i], nums[idx]);
            
            
        }
        
    }
    
    
    vector<vector<int>> permute (vector<int>& nums) {
        vector<vector<int>> ans;
        perm(nums, ans , 0);
        return ans;
    }
    
};