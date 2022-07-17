class Solution {
public:
    
    
    
    vector<int> twoSum(vector<int>& nums, int target) {
    
        
        int n = nums.size();
         
        for(int i  = 0 ; i < n  ; i++){
            
            int toFind = target - nums[i];
            
            std::vector<int>::iterator  it;
            
            it = find(nums.begin() +1+i, nums.end() , toFind);
            
            if(it != nums.end()){
                int idx = it - nums.begin();
                return {idx, i};
                
            }
            
            
            
        }
        
        
        return {-1, -1};
        
        
    }
};