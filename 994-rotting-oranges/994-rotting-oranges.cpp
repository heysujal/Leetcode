class Solution {
public:
    
    void rot(vector<vector<int>>&grid, pair<int, int> p, queue<pair<int, int>> &q, int &fresh)
    {
        
        int m = grid.size();
        int n = grid[0].size();
        int i = p.first;
        int j = p.second;
        
        vector<pair<int, int>> coords= {{-1, 0} , {1 , 0}, {0 , -1}, {0, 1}};
        
        for(auto xy : coords)
        {
            
            int x  = xy.first;
            int y  = xy.second;
            
            if( i + x >= 0 and i + x < m and j + y < n and j + y >= 0 and grid[i+x][j+y] == 1)
            {
                grid[i + x][j + y] = 2;
                q.push(make_pair(i + x, j + y));
                fresh--;
            }
            
            
        }
        
        
        
            
//         if( i + 1 < m and grid[i + 1][j] == 1)
//         {
//             grid[i+1][j] = 2;
//             q.push(make_pair(i+1, j));
//             fresh--;
//         }
            
//         if( j - 1 >= 0 and grid[i][j - 1] == 1)
//         {
//             grid[i][j - 1] = 2;
//             q.push(make_pair(i, j - 1));
//             fresh--;
//         }
            
//         if( j + 1 < n and grid[i][j + 1] == 1)
//         {
//             grid[i][j + 1] = 2;
//             q.push(make_pair(i, j + 1));
//             fresh--;
//         }
            
        
        
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