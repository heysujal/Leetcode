class Solution {
public:
    string reverseWords(string s) {
       
        string ans="";
        string temp;
        bool onespace = false;
        for(int i = s.size() -1; i >=0 ; i--)
        {
            
           
            if(s[i]!=' ')
                {
                    temp.push_back(s[i]);
                    onespace = true;
                }
            else if(onespace){
                
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans += " ";
                temp = "";
                onespace=false;
                
            }
            
            
            
        }
        
        reverse(temp.begin(), temp.end());
        ans+= temp;    
        if(ans[ans.size()-1]==' ')
            ans.pop_back();
        return ans;
        
        
    }
};