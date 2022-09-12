class Solution {
public:
    int rob(vector<int>& nums) {
        
        // lets say I start from [index....n-1]
        
        int n = nums.size();
        int  f= 0; // answer for index >=n
        int s= nums[n-1]; // answer for index n-1
        
        
        for(int i = n-2; i>=0 ; i--)
        {
            
            
            int pick = nums[i] + f;
            int skip = s;
            
            int curr = max(pick, skip);
            
            f = s;
            s= curr;
    }
        
        
        return s;
        
        
        
    }
};