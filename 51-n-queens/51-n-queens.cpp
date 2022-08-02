class Solution {
public:
    
    bool isSafe(int i ,int j , vector<string> &board)
    {
        
        // we check if queen is places upward, left diagonal and right diagonal
        
        int tempI = i;
        
        // check up 
        while(tempI>=0)
        {
            
            if(board[tempI][j]=='Q')
                return false;
            tempI--;
            
        }
        // go upward left
        
        tempI = i ;
        int tempJ =  j;
        while( tempI >= 0 and tempJ >= 0)
        {
            if(board[tempI][tempJ]=='Q')
                return false;
            tempI--;
            tempJ--;
            
        }
        
        // go upward right direction
        
        tempI = i;
        tempJ =  j;
        
        while(tempI>=0 and tempJ < board[0].size())
        {
            if(board[tempI][tempJ] == 'Q')
                return false;
            tempI--;
            tempJ++;
            
        }
        
        
        return true;
    }
    
    void solve(int i ,  vector<string> &board,   vector<vector<string>> &ans)
        
    {
        // base case
        // if all rows has been filled
        if( i == board.size())
        { 
            ans.push_back( board);
            return ;
        } 
        
        
        
        
        // explore all safe columns and further recursive calls
        
        for(int j = 0 ; j < board[0].size() ; j++)
        {
            if( isSafe(i , j , board))
            {
                board[i][j] = 'Q';
                // now try placing in next row
                solve(i+1, board, ans);
                //backtrack
                board[i][j] = '.';
            
            
            }
        }
        
        
        
        
        
        
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        
    vector<string> board(n , string(n, '.'));
     
      vector<vector<string>> ans;    
        solve(0 , board, ans);
 
        return ans;
    }
};