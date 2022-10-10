class Solution {
public:
    
    
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        
        
        for(int i =0 ; i < nums.size() - 2; i++)
        {
            
            if( i == 0 or i > 0 and nums[i] != nums[i-1])
            {
                
                int low = i+1;
                int high = nums.size() -1;
                
                int target = - nums[i];
                
                
                while(low < high)
                {
                    
                    if(nums[low] + nums[high] == target)
                    {
                        
                        res.push_back({nums[i], nums[low], nums[high]});
                        
                        while(low < high and nums[low] == nums[low+1])
                            low++;
                        while(low < high and nums[high] == nums[high-1])
                            high--;
                        
                        low++;
                        high--;
                    }
                    
                    else if(nums[low] + nums[high] < target){
                        low++;
                    }
                    else{
                        high--;
                    }
                
                }
                
                
                
            }
            
            
        }
        return res;
        
        
    }
};