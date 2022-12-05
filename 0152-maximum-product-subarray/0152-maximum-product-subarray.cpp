class Solution {
public:
    int maxProduct(vector<int>& a) {
        int prev_max_prod = a[0];
        int prev_min_prod = a[0];
        int curr_max_prod = a[0];
        int curr_min_prod = a[0];
        int ans = a[0];
        
        for(int i = 1; i < a.size() ; i++)
        {
            
            curr_max_prod = max(prev_max_prod*a[i],max(prev_min_prod*                                 a[i],a[i]));
            
            curr_min_prod = min(prev_max_prod*a[i],min(prev_min_prod*                                 a[i],a[i]));
            
            ans = max(ans, curr_max_prod);
            
            prev_max_prod = curr_max_prod;
            prev_min_prod = curr_min_prod;            
        }
        
        return ans;
        
    }
};