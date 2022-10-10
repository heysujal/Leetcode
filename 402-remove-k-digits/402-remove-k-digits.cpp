class Solution {
public:
    string removeKdigits(string num, int k) {
        
        // Using string as a stack 
        // push_back() and pop_back()
        
       string ans="";
        for(char &c:num)
        {
            while(ans.size() && ans.back()>c &&k)
            {
                ans.pop_back();
                k--;
            }
            if(ans.size()||c!='0')ans.push_back(c);
        }
            // <-------this look is to make sure we fulfil the deletion condition
        while(ans.size()&&k--)          
        {
            ans.pop_back();
        }
        return (ans=="")?"0":ans;
        
        
    }
};