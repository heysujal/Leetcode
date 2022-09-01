class Solution {
public:
    
    
    bool solve(int idx, int left , int right, int n , vector<int> &nums)
        
    {
        int leftSum = 0;
        int rightSum = 0;
        
        if(left < 0)
            leftSum = 0;
        else
        {
             for(int p = 0; p <= left ; p++)
                leftSum += nums[p];
        }
        
        if(right >= n)
            rightSum = 0;
        
        else{
           
            for(int q = right; q <= n-1 ; q++)
                rightSum+=nums[q];
        }
        
        
        return (leftSum==rightSum);
        
    
    }
    
    
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        int i =0 ;
        
        for(auto &mid : nums)
        {
            if(solve(i , i-1, i+1 , n, nums))
                return i;
            i++;
        }
        return -1;
        
    }
};