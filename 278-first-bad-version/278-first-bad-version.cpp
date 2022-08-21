// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    
    int firstBadVersion(int n) {
        
        int high = n;
        int low = 1;
 
        int lastGood = 0;
        int firstBad = n;
        while(low<=high)
        {
            int mid  = low +(high-low)/2;
            
            if(isBadVersion(mid))
                {
                
                firstBad = mid;
                
                high = mid-1;
            
            
            }
            else
            {
                lastGood = mid;
                low = mid+1;
            }
                
            
            
            
        }
        cout<<"lastGood "<<lastGood<<"\nfirstBad "<<firstBad;
        return low;
        
        
    }
};