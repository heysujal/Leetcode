class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        unordered_set<char> st;
        int ans = 0;
        int i =0 , j = 0;
        int n = s.size();
        while( i < n and j < n)
        {
            
            if(st.find(s[j]) == st.end()){            
                
                st.insert(s[j]);
                ans = max(ans , j - i + 1);
                j++;
                
            }   
            
                                          
            // present in set already
            // then we need to start a new subarray
            else{
                
                st.erase(s[i]);
                i++;
                
                
            }
            
            
            
        }
        
        return ans;
        
    }
 
};