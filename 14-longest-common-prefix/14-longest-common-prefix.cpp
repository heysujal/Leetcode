class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = "";
        
        
        for(int i = 0 ; i < strs[0].size() ; i++){
            char ch = strs[0][i];
            bool match = true;
            
            
            // now we check with other strings 
            
            
            for(int j = 1  ; j <  strs.size() ; j++){
      
                    
                    //not match 
                    
                    if(strs[j].size() < i or ch != strs[j][i]){
                        
                        match = false;
                        break;     
                    
                }
                
                
                
            }
            
            
            if(match == false)
                break;
            else
                ans.push_back(ch);
            
            
            
            
        }
        return ans;
        
    }
};