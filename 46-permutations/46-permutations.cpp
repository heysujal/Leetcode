class Solution {
public:
    
    int fact(int n)
    {
        
        if(n==0)
            return 1;
        
        return n*fact(n-1);
        
    }
    
    void nextPermutation(vector<int>& nums) {
	    // Optimal Solution Time O(N) & Auxiliary Space O(1)
	    // Narayana Panditha's Algorithm
        int len=nums.size(), k=0, l=0;
        for(k=len-2;k>=0;k--){
            if(nums[k]<nums[k+1])
                break;
        }
        if(k<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(l=len-1;l>k;l--){
                if(nums[l]>nums[k])
                    break;
        }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        
        vector<vector<int>> ans;
        int n = nums.size();
        
        int len = fact(n); 
        ans.push_back(nums);
        
        for(int i = 0 ; i < len-1;i++)
        {
            nextPermutation(nums);
            ans.push_back(nums);
        }
        
        return ans;
        
    }
};