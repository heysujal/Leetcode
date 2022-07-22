class Solution {
public:
    bool isPalindrome(string s) {
        
        if(s.size()==0)
            return true;
        
        
        string temp="";
        
        for(auto x:  s)
        {
            
            if(isalpha(x) or isdigit(x))
                temp+= tolower(x);
            
        }
        string rev = temp;
        reverse(rev.begin(), rev.end());
        
        
        
        
        return (rev==temp);
        
        
    }
};