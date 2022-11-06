//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
  int solve(int i, int price[], int n )
  {
      
    //   base cases
    
    if(i==0)
    {
        
        return n*price[0];
        
    }
      
      int skip = 0 + solve(i-1, price, n);
      
      int pick = INT_MIN;
      int rodlength = i + 1;
      
      if(rodlength <= n)
        pick  = price[i]  + solve(i, price, n - rodlength);
        
        
      return max(pick, skip);
  } 
  int solveMemo(int i, int price[], int n, 
  vector<vector<int>> &dp )
  {
      
    //   base cases
    
    if(i==0)
    {
        
        return n*price[0];
        
    }
      
    if(dp[i][n] != -1)
        return dp[i][n];
  int skip = 0 + solve(i-1, price, n);
  
  int pick = INT_MIN;
  int rodlength = i + 1;
  
  if(rodlength <= n)
    pick  = price[i]  + solve(i, price, n - rodlength);
    
    
  return dp[i][n] = max(pick, skip);
  }
  
  int solveTab(int price[], int n)
  {
      vector<vector<int>> dp(n , vector<int>(n+1, 0));
      
      for(int c = 0; c<= n ; c++)
        dp[0][c] = c * price[0];
        
      for(int i = 1; i < n ; i++)
      {
          
          for(int j = 0; j <= n; j++)
          {
              
              int skip = 0 + dp[i-1][j];
              int pick = -1e9;
              
              int rod_length = i + 1;
              if(rod_length <= j)
                pick = price[i] + dp[i][j-rod_length];
                
              dp[i][j]= max(skip, pick);    
              
              
              
          }
          
      }
      
      return dp[n-1][n];
      
  }
  
  int solveSpace(int price[], int n)
  {
      
            
      vector<int> prev(n+1, 0), curr(n+1, 0);
      for(int c = 0; c<= n ; c++)
        prev[c] = c * price[0];
        
      for(int i = 1; i < n ; i++)
      {
          
          for(int j = 0; j <= n; j++)
          {
              
              int skip = 0 + prev[j];
              int pick = -1e9;
              
              int rod_length = i + 1;
              if(rod_length <= j)
                pick = price[i] + curr[j-rod_length];
                
              curr[j]= max(skip, pick);    
              
              
              
          }
          
          prev = curr;
          
      }
      
      return prev[n];
      
      
  }
  
  
  int solveSpaceUltimate(int price[], int n)
  {
      
            
      vector<int> prev(n+1, 0);
      for(int c = 0; c<= n ; c++)
        prev[c] = c * price[0];
        
      for(int i = 1; i < n ; i++)
      {
          
          for(int j = 0; j <= n; j++)
          {
              
              int skip = 0 + prev[j];
              int pick = -1e9;
              
              int rod_length = i + 1;
              if(rod_length <= j)
                pick = price[i] + prev[j-rod_length];
                
              prev[j]= max(skip, pick);    
              
              
              
          }
          
     
          
      }
      
      return prev[n];
      
      
  }
 
    int cutRod(int price[], int n) {
        
        
        // return solve(n-1,price, n);
        // vector<vector<int>> dp(n , vector<int>(n+1, -1));
        // dp[i][j] represents max value that can be obtained 
        // from index 0.....i with the original rod lenght
        // being j
        
        // return solveMemo(n-1,price, n, dp);
        
        // return solveTab(price, n);
        // return solveSpace(price, n);
        
        return solveSpaceUltimate(price, n);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends