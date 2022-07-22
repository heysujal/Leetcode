class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        
          string s = to_string(x);
        
        int i  =0;
        int j = s.size() - 1;
        
        while(i <= s.size() /2 and j >= s.size()/2)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
                
            }else{
        return false;
                
            }
        }
        
        return true;
    }
};