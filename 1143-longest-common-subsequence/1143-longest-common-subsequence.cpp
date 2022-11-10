class Solution {
public:
    
    int solve(int i, int j , string &s, string &t)
    {
        
        if(i < 0 or j < 0)
            return 0;
        
        
        //matching characters
        
        if(s[i] == t[j])
            return 1 + solve(i-1, j-1, s, t);
        
        return 0 + max(solve(i-1, j , s ,t), 
                       solve(i, j-1, s, t));
        
        
    }
    
    
    int solveMemo(int i, int j , string &s, string &t
                 ,vector<vector<int>> &dp)
    {
        
        if(i < 0 or j < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        //matching characters
        
        if(s[i] == t[j])
            return dp[i][j] = 1 + solve(i-1, j-1, s, t);
        
        return dp[i][j] = 0 + max(solve(i-1, j , s ,t), 
                       solve(i, j-1, s, t));
        
        
    }
    
    
    int solveTab(string &s, string &t) {
        
        int size1 = s.size();
        int size2 = t.size();
        
        
       
        vector<vector<int>> dp(size1 +1, vector<int>(size2 + 1, 0));
        
        // iterating for size2
        for(int q = 0 ; q <= size2 ; q++)
        {
                dp[0][q] = 0;    
        }
        
        // iterating for size1
        for(int q = 0 ; q <= size1 ; q++)
        {
                dp[q][0] = 0;            
        }
        for(int i = 1 ; i <= size1 ; i++)
        {
            
            for(int j = 1 ; j <= size2 ; j++)
            {
                
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else 
                    dp[i][j] = 0 + max(dp[i-1][j] , dp[i][j-1]);                 
            }
            
        }
        
        return dp[size1][size2];
        
    }    int solveSpace(string &s, string &t) {
        
        int size1 = s.size();
        int size2 = t.size();
        
        
       
        
         vector<int> prev(size2+1, 0), curr(size2 + 1, 0);
        
       
        
        for(int i = 1 ; i <= size1 ; i++)
        {
            
            for(int j = 1 ; j <= size2 ; j++)
            {
                
                if(s[i-1] == t[j-1])
                    curr[j] = 1 + prev[j-1];
                
                else 
                    curr[j] = 0 + max(prev[j] , curr[j-1]);                 
            }
            
            prev = curr;
            
        }
        
        return prev[size2];
        
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int size1 = text1.size();
        int size2 = text2.size();
        
        
        // return solve(size1 - 1, size2 - 1, text1, text2);
        // vector<vector<int>> dp(size1, vector<int>(size2, -1));
        // return solveMemo(size1 - 1, size2 - 1, text1, text2,dp);
        
        return solveSpace(text1, text2);
        
    }
};