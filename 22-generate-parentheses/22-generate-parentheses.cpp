class Solution {
public:
       bool isValid(string s) {
        
        int n = s.size();
        stack<char> st;
        for(int i =0 ;i < n ; i++){
             char ch = s[i];
            
            if(ch=='(' or ch=='[' or ch == '{'){
                st.push(ch);
                
            }else{
                //closing bracket comes in
                if(st.empty()==true)
                    return false;
                
                // when st is not empty
                
                char top = st.top();
                if((top=='(' and ch==')') or (top=='[' and ch==']') or (top=='{' and ch=='}'))      {
                    st.pop();
                    
                }else{
                return false;
                    
                }
                
                
            }
            
            
            
            
        }
        
        if(st.size()==0)
            return true;
        return false;
        
        
        
        
    }
    void solve(int i ,int n, string &temp, vector<string> &ans )
    {
        
        if( i== 2*n)
        {
            if(isValid(temp))
                ans.push_back(temp);
            
            
            return;
        }
        
        // pick )
        
        temp.push_back('(');
        solve(i+1, n, temp, ans);
        
        //skip
        temp.pop_back();
        temp.push_back(')');
        solve(i+1, n, temp, ans);
        temp.pop_back();
        
        
        
        
    }
    
    
    vector<string> generateParenthesis(int n) {
        
        
        vector<string> ans;
        
         string temp;
        
         solve(0,n, temp, ans);
        
        return ans;
        
        
    }
};