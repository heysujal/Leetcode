class Solution {
public:
    
    
    int bs(vector<int> arr, int low , int high, int target)
    {
        
        while(low< high)
        {
            int mid = low + (high-low)/2;
            
            if(arr[mid]>=target)
            {
                high = mid;
            }
            else
                low = mid+1;
               
        }
        
        return (arr[low]==target)?low : -1;
        
    }
    
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       
        int n = matrix[0].size() ;
        for(int i =0  ; i < matrix.size() ; i++)
        {
            
            if(target <= matrix[i][n-1])
            {
                
                if(bs(matrix[i],0,n-1,target)==-1)
                    return false;
                return true;
                
            }
            
            
        }
        
        return false;
    }
};