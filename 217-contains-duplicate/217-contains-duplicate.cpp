class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int, int> mp;
        for(auto x: nums){
            
            if(++mp[x] > 1)
                return true;
            
            
        }
        return false;
        
        
    }
};