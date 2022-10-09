class Solution {
public:
    
    void rot(vector<vector<int>>&grid, pair<int, int> p, queue<pair<int, int>> &q, int &fresh)
    {
        
        int m = grid.size();
        int n = grid[0].size();
        int i = p.first;
        int j = p.second;
        
        if( i - 1 >= 0 and grid[i-1][j] == 1)
        {
            grid[i-1][j] = 2;
            q.push(make_pair(i-1, j));
            fresh--;
        }
            
        if( i + 1 < m and grid[i + 1][j] == 1)
        {
            grid[i+1][j] = 2;
            q.push(make_pair(i+1, j));
            fresh--;
        }
            
        if( j - 1 >= 0 and grid[i][j - 1] == 1)
        {
            grid[i][j - 1] = 2;
            q.push(make_pair(i, j - 1));
            fresh--;
        }
            
        if( j + 1 < n and grid[i][j + 1] == 1)
        {
            grid[i][j + 1] = 2;
            q.push(make_pair(i, j + 1));
            fresh--;
        }
            
        
        
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int time = 0;
        queue<pair<int, int>> q;
        
        for(int i = 0; i < m ; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                
                if(grid[i][j] == 2)
                    q.push(make_pair(i , j));
                else if(grid[i][j] == 1)
                    fresh++;
                    
                
            }
        }
        
        if(fresh == 0)
            return 0;
        
        
        
        
        while(!q.empty())
        {
            bool flag = true;
            int size = q.size();
            time++;
            for(int t = 0; t < size ; t++)
            {
                auto p = q.front();
                q.pop();
                
                // rot all directions from this x,y
                
                rot(grid, p,q , fresh);
                
                if(fresh == 0)
                {
                    flag = false;
                    break;
                }
            }
            
            if(!flag)
                break;
        }
        
        if(fresh > 0 or fresh < 0)
            return -1;
            
        return time;
        
    }
};