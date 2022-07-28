class Solution {
public:
    
    
       void help(int i ,int k, int &sumtillnow,int &target,  vector<int> &subset, vector<vector<int>> &ans)
        
    {
        
           if(sumtillnow == target and k==0)
        {
            ans.push_back(subset);
            return ;
            
        }
        
        if(k > 10-i or sumtillnow > target)
            return ;
        if(i == 10)
            return ;
     
        
    
        
        help(i+1  ,k, sumtillnow,target , subset, ans);
      
        
        // pick element
        subset.push_back(i);
        sumtillnow += i;
           
        help(i+1 ,k-1,sumtillnow , target , subset, ans );
        sumtillnow -= i;
        subset.pop_back();
        
            
        
        
        
    }
    
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subset;
        int sumtillnow = 0;
        
       
        // vector<int> nums(9);
        // iota(nums.begin(), nums.end() , 1);
        
        
        
        help(1 ,k , sumtillnow,n,subset , ans );
        
        
        return ans;
        
    }
};