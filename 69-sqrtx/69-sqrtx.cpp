class Solution {
public:
   int mySqrt(int x) {
  
    int low = 0 ;
    int high = x;
        
       if(x==0 or x==1)
           return x;
        
    while(low < high)
    {
        int mid = low+(high-low)/2;
        
        
        if(mid <= x/mid)
             low = mid+1;
        else
            high = mid;
      
        
    }
        
 
    return low-1;    
    }
};