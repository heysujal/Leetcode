class Solution {
public:
   int mySqrt(int x) {
  
    long long int low = 0 ;
    long long int high = x;
 
        
    while(low < high)
    {
        long long int mid = low+(high-low)/2;
        
        
        if(mid*mid>= x)
             high = mid;
        else
           low = mid+1;
      
        
    }
        
 
    return (x==low*low)?low:low-1;    
    }
};