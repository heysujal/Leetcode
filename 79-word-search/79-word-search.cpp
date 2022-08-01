class Solution {
public:
    
    
    bool find(int i ,int j, vector<vector<char>>& board, string &word, int k )
        
        
    {
        
        if(k==word.size())
            return true;
        
       
        
        // if not found
        if(i < 0 or j < 0 or i == board.size() or j == board[0].size()
          or board[i][j] != word[k])
        {
            return false;
            
        }
    
        
        //mark as visited 
        board[i][j] = '0';
        // right
        
        bool ans = find(i, j+1, board, word, k+1 )
                        or
            find(i+1, j, board, word, k+1)
            or
            find (i, j-1, board, word, k+1)
            or
            find(i-1, j, board, word, k+1);
        
  	//change the character back for other searches
        board[i][j] = word[k];
        return ans;
        
        
    }
    
    
    
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i =  0; i < board.size() ; i++){
            
            
            for(int j = 0; j < board[i].size(); j++)
            {
                if(find(i , j , board, word, 0))
                {
                    return true;
                    
                }
            }
            
        }
        
        return false;
        
    }
};