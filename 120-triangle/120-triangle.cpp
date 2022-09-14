class Solution {
public:
    
    int solve(int i ,int j , vector<vector<int>> triangle)
    {
        int m = triangle.size();
         
        
        if(i==m-1)
            return triangle[i][j];
         
        
       int  down = triangle[i][j] + solve(i+1, j , triangle);
       int right = triangle[i][j] + solve(i+1, j+1, triangle);
        
        return min(down, right);
    
    }
    int solveMemo(int i ,int j , vector<vector<int>> triangle, vector<vector<int>> &dp)
    {
        int m = triangle.size();
         
        
        if(i==m-1)
            return triangle[i][j];
        
        
         if(dp[i][j]!=-1)
             return dp[i][j];
        
       int  down = triangle[i][j] + solveMemo(i+1, j , triangle, dp);
       int right = triangle[i][j] + solveMemo(i+1, j+1, triangle, dp);
        
        return dp[i][j] = min(down, right);
    
    }
    
    
    int solveTab(vector<vector<int>>& triangle)
    {
       int m = triangle.size();
        
       vector<vector<int>> dp(m ,vector<int>(m, -1));
        // dp[i][j] stores answer for [i][j] to the last row
        
        // filling in the base cases
        
        for(int i = 0; i < m ; i++)
        {
            dp[m-1][i] = triangle[m-1][i];
            
        }
        
        
         
        
        
        for(int i = m-2; i>=0 ; i--)
        {   
            
            
            for(int j = triangle[i].size()- 1; j>=0; j--)
            {
                
                int  down = triangle[i][j] + dp[i+1][j];
                int right = triangle[i][j] + dp[i+1][j+1];
        
                 dp[i][j] = min(down, right);
            }
        }
        
        return dp[0][0];
        
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
          int m = triangle.size();
          
          vector<vector<int>> dp(m ,vector<int>(m, -1));
        
          // return solveMemo(0 , 0 , triangle, dp);
        return solveTab(triangle);
        
          
        
    }
};