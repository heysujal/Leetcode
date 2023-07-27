class Solution {
public:
    void helper(int open , int close, int n , string str, vector<string> &ans){
        if(str.size() == 2*n){
            ans.push_back(str);
            return;
        }
        if(open < n)
            helper(open+1, close, n , str + '(', ans);
        if(close < open)
            helper(open, close+1, n , str+')', ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(0,0,n,"", ans);
        return ans;
    }
};