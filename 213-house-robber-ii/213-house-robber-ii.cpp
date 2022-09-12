class Solution {
public:
    int solve(vector<int>& nums) {
        
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
    
    
    
    
    
    int rob(vector<int>& nums) {
        
        vector<int> temp1, temp2;
        
        int n = nums.size();
        if(n==1)
            return nums[0];
        
        
        for(int i =0 ; i < n; i++)
        {
            if(i!=n-1)
                    temp1.push_back(nums[i]);
            if(i!=0)
                    temp2.push_back(nums[i]);
            
            
        }
        
        int ans1 = solve(temp1);
        int ans2 = solve(temp2);
        
        return max(ans1 , ans2);
        
    }
};