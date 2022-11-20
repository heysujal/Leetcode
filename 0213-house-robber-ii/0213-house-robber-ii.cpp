class Solution {
public:

int solve(int i,vector<int> &nums)
{
    int n = nums.size();
    if( i >= n)
    {
        return 0;
    }
    //pick
    int pick = nums[i] + solve(i+2, nums);
    //skip
    int skip = solve(i+1, nums);
    
    return max(pick, skip);
 }



int solveMemo(int i,vector<int> &nums, vector<int> &dp)
{
    int n = nums.size();
    if( i >= n)
    {
        return 0;
    }
    if(dp[i] != -1)
        return dp[i];
    //pick
    int pick = nums[i] + solveMemo(i+2, nums, dp);
    //skip
    int skip = solveMemo(i+1, nums, dp);
    
    return dp[i] = max(pick, skip);
}

int solveSpace(int n, vector<int> &nums){
//    What is dp[i] represents solution from index i to n-1
   
   int f = nums[n-1];
   int s = 0;
    
    for(int i = n-2 ; i >= 0 ; i--)
    {
        
        int pick = nums[i];
        int skip = 0;
        
        if(i + 2 <= n-1)
            pick = nums[i] + s;
        skip = f;
        
        int sum  = max(skip, pick);
        s = f;
        f = sum;
        
    }
    
    return f;
 
    
}

int fun(vector<int> &nums){
    int n = nums.size();
    // return solve(0, nums);
//    What is dp[i] represents solution from index i to n-1
    // vector<int> dp(n , -1);
    // return solveMemo(0, nums, dp);
    
     return solveSpace(n, nums);
    
}
    
    int rob(vector<int>& nums) {
        
    vector<int> v1;
    vector<int> v2;
    int n = nums.size();  
    if(n == 1)
        return nums[n-1];
    for(int i = 0 ; i <= n-2 ; i++)
    {
        v1.push_back(nums[i]);
    }
        
    for(int i = 1 ; i <= n-1 ; i++)
    {
        v2.push_back(nums[i]);
    }
    
    return max(fun(v1), fun(v2));
    }
};