class Solution {
public:
    
    
    
    int mySqrt(int x) {
        
    if(x==0 or x==1)
        return x;
    int low = 0 ;
    int high = x;
        
        
    while(low < high)
    {
        int mid = low+(high-low)/2;
        
        
        if(mid!=0  and mid <= x/mid)
             low = mid+1;
        else
            high = mid;
      
        
    }
        
 
    return low-1;    
    }
};