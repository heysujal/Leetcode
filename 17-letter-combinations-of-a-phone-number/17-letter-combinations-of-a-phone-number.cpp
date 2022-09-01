class Solution {
public:
    
    
    
    void solve(int idx,string &digits, string &temp , vector<string> &ans)
    {
        vector<string>v= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(idx==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        
        
        string s = v[digits[idx] - '0'];
        

        for(int i =0 ; i < s.size()  ; i++)
        {
            
            
            temp.push_back(s[i]);
            
            solve(idx+1, digits, temp , ans);
            temp.pop_back();
        }
        
        
        
        
    }
    
    
    vector<string> letterCombinations(string digits) {
        
        if(digits=="")  return {};
        
           vector<string> ans;
            string temp;
        int i =0 ;
        
        solve(i ,digits, temp, ans);
        return ans;
    }
};