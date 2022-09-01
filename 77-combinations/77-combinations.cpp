class Solution {
public:
    
    
    void solve(int i , int n,int k ,vector<int> &temp,vector<vector<int>> &ans )
    {
        if(k==0)
        {
            ans.push_back(temp);
            return;
        
        }
        
        
        
        if(i==n)
            return;
        
        
        // pick
        
        temp.push_back(i+1);
        solve(i+1, n, k-1, temp, ans);
        temp.pop_back();
        
        // skip
        
        solve(i+1, n , k ,temp, ans);
        
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> temp;
        vector<vector<int>> ans;
        
        int i = 0;
        solve(i , n,k, temp, ans);
        
        return ans;
    }
};