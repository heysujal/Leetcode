class Solution {
public:
    
    int ls(vector<int> &nums, int target)
    {
        for(int i =0   ; i < nums.size() ; i++)
        {
            if(nums[i]==target)
                return i;
        }
        
        return -1;
        
        
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        
        
        for(int i  = 0; i < nums1.size() ; i++)
        {
            int idx = ls(nums2, nums1[i]);
            int temp = -1;
            for(int j = idx+1; j < nums2.size(); j++)
            {
                if(nums1[i] < nums2[j])
                {
                    temp = nums2[j];
                    break;
                }
            }
            
            ans.push_back(temp);
            
        }
        
        return ans;
        
    }
};