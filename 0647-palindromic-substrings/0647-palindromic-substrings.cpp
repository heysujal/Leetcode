class Solution {
public:
    
    
    int countSubstrings(string s) {
        
        int n = s.size();
        if(n < 2)
            return n;
        
        
        int count = 0;
        int i;
        int j;
        int k;
        
        for(  i = 0 ; i < s.size() ; i++)
        {
            
            // for odd
            
              j = i;
              k = i;
            
            while(j >= 0 and k < n and s[j] == s[k])
            {
                
                j--;
                k++;
                
                count++;
            
            }
            
            
            
            // for odd
            
              j = i;
              k = i+1;
            
            while(j >= 0 and k < n and s[j] == s[k])
            {
                
                j--;
                k++;
                
                count++;
            
            }
            
            
        }
        
        return count;
    }
};