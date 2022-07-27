class Solution {
public:
    
      void  solve( int i, int n , int k , vector<int> &subset, vector<vector<int>>&ans )
        
    {         
         if(k==0 )
        {
            ans.push_back(subset);     
            return;
        }
          
          if(k > n-i+1)
              return;
          if(i>n)
              return;
      
       //pick
       subset.push_back(i);
       solve(   i+1, n , k-1, subset, ans);
       subset.pop_back();
       
       // skip
      
       solve( i+1, n , k ,subset, ans);
        
        
        
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> subset;
        vector<vector<int>> ans;
        solve(1, n ,k , subset, ans);
        return ans;
        
    }
};