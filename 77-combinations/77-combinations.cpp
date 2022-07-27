class Solution {
public:
    
      void  solve(vector<int> &nums,int i, int n , int k , vector<int> &subset, vector<vector<int>>&ans )
        
    {         
         if(k==0 )
        {
            ans.push_back(subset);     
              return;
        }
            
        if(i==n)
            return;
        if(k > n-i)
            return ;
      
       //pick
       subset.push_back(nums[i]);
       solve( nums,  i+1, n , k-1, subset, ans);
       subset.pop_back();
       
       // skip
      
       solve(nums,i+1, n , k ,subset, ans);
        
        
        
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> subset;
        vector<vector<int>> ans;
        
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        
        solve(nums ,0, n ,k , subset, ans);
        return ans;
        
    }
};