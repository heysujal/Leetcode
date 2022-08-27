class Solution {
public:
    void reverseString(vector<char>& s) {
        
        stack<char> s2;
        
        for(auto x:s)
            {
             s2.push(x);
            }
        for(auto &x: s)
        {
            x = s2.top();
            s2.pop();
            
        }
            
        
    }
};