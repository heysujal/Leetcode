class Solution {
public:
    
    // function to give required number of days for a certain capacity cap
    int reqDays(int cap, vector<int>& arr)
    {
        int reqDays = 1;
        int remainingCap = cap;
        int n = arr.size();
        
        for(int i = 0; i < n; i++)
        {   
            // if weight of an item is more than the capacity of ship itself
            if(arr[i] > cap)
                return INT_MAX;
            
            if(arr[i] <= remainingCap)
            {
                remainingCap -= arr[i];
                continue;
            }
            
            else
            {
                
                reqDays++;
                remainingCap = cap;
                remainingCap -= arr[i];
                
                
            }
            
        }
        
        
         
        return reqDays;
        
        
    }
    
    
    int shipWithinDays(vector<int>& weights, int D) {
        
        int ans = -1;
        
        int low = 1;
         
        int n = weights.size();
        int high = 0;
        
        for(auto x : weights)
            high += x;
         
        
       while(low <= high)
       {
           
           int cap = low + (high - low)/2;
           
           if(reqDays(cap, weights) <= D)
           {
               ans = cap;
               high = cap - 1;
           }
           else
           {
               low = cap + 1;
           }
           
           
       }
        
        return ans;
        
    }
};