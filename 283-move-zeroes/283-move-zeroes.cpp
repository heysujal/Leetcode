class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        vector<int> ans(nums.size() , 0);
        
        int i  = 0;
        for(auto x: nums)
            if(x != 0)
                ans[i++] = x;
        
        nums = ans;
    }
};