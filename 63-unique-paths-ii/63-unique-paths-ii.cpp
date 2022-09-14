class Solution {
public:
    
    
    int solveMemo(int i , int j, vector<vector<int>> &dp,vector<vector<int>> &grid)
    {
        if(i<0 or j <0 or grid[i][j]==1)
            return 0;
        if(i==0 and j==0)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int up = solveMemo(i-1,j, dp, grid);
        int left = solveMemo(i , j-1, dp, grid);
        
        return dp[i][j] = up + left;
        
        
        
    }
    
    int solveTab(int m , int n, vector<vector<int>> &grid)
    {
        
        vector<vector<int>> dp(m , vector<int>(n, 0));
         
        for(int i =0 ; i < m ; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                 
                if(!i and !j and !grid[i][j]) 
                    dp[i][j] = 1;
                else if(!i and !j and grid[i][j])
                    dp[i][j] = 0;
                else if(grid[i][j] == 1) 
                    dp[i][j] = 0;
                else{
                    
                    int up = 0;
                if(i>0)
                    up = dp[i-1][j];
                
                int left =0;
                if(j>0) 
                    left = dp[i][j-1] ;
        
                 dp[i][j] = up + left;
                    
                    
                }
                
                
            }
        }
        
        return dp[m-1][n-1];
        
    }
    
    
    int solveSpace(vector<vector<int>>& grid)
    {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> dummy(n , 0);
        
        
        for(int i = 0; i < m ; i++)
        {
            
            vector<int> curr (n , 0);
            for(int j =  0 ; j < n ;j++)
            {
                
                // for curr[0]
                if(!i and !j and !grid[i][j])
                    curr[j] = 1;
                 
                
                // for rest
                else if(grid[i][j]==1)
                    curr[j] = 0;
                
                else{
                    
                    int up = 0;
                    int left = 0;
                    if(i>0)
                        up = dummy[j];
                    if(j>0)
                        left = curr[j-1];
                    
                    curr[j] = up + left;
                    
                    
                }
                
                
                
            }
            
            dummy = curr;
            
        }
        
        return dummy[n-1];
        
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        // return solveMemo(m-1, n-1, dp, grid);
        
        // return solveTab(m, n , grid);
        return solveSpace(grid);
        
    }
};