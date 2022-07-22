class Solution {
public:
    
    vector<vector<int>> solve(vector<int> &nums, int i )
        
    {
        if(i == nums.size() )
            return {{}};
        
        
      vector<vector<int>> partialAns = solve(nums, i+1);
      vector<vector<int>> finalAns;
        
        for(auto x: partialAns)
            finalAns.push_back(x);
        
          
        for(auto x: partialAns)
        {
            x.push_back(nums[i]);
            finalAns.push_back(x);
        } 
        
        
        return finalAns;
        
        
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
         return solve(nums, 0);
        
    }
};