class Solution {
public:
    
    int solve(int i, int j1, int j2,vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(j1 >= n or j2>=n or j1<0 or j2<0)
        {
            return -1e8;
        }
                  
        if(i==m-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];
                
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        
        int maxi = 0;
        for(int dj1 = -1 ; dj1<=1; dj1++)
        {
            
            for(int dj2 = -1 ; dj2<=1; dj2++)
            {
                int value;
                
                if(j1==j2)
                    value = grid[i][j1];
                else 
                    value = grid[i][j1] + grid[i][j2];
                 
                int ans = value + solve(i+1, j1 + dj1, j2+dj2, grid);
                maxi = max(maxi, ans);
                 
            }
            
            
        }
                  
           return maxi;       
    }
    
    
      int solveMemo(int i, int j1, int j2,vector<vector<int>>& grid, vector<vector<vector<int>>> &dp)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(j1 >= n or j2>=n or j1<0 or j2<0)
        {
            return -1e8;
        }
                  
        if(i==m-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];
                
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
          
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        
        
        int maxi = 0;
        for(int dj1 = -1 ; dj1<=1; dj1++)
        {
            
            for(int dj2 = -1 ; dj2<=1; dj2++)
            {
                int value;
                
                if(j1==j2)
                    value = grid[i][j1];
                else 
                    value = grid[i][j1] + grid[i][j2];
                 
                int ans = value + solveMemo(i+1, j1 + dj1, j2+dj2, grid,dp);
                maxi = max(maxi, ans);
                
                 
            }
            
            
        }
                  
           return dp[i][j1][j2] = maxi;      
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        // return  solve(0, 0 ,n-1, grid);
        
        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n, vector<int>(n, -1)));
        return solveMemo(0, 0 , n-1, grid, dp);
        
        
        
    }
};