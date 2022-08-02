class Solution {
public:
    
    void fill(int i , int j, vector<vector<int>>& image, int oldcolor, int newcolor, int m , int n)
    {
        
        
        if( i < 0 or j < 0 or i >= n or j>=m or image[i][j]!=oldcolor)
            return;
        
        
        // otherwise
        image[i][j] = newcolor;      
        fill(i+1, j , image, oldcolor, newcolor, m , n);
        fill(i-1, j , image, oldcolor, newcolor, m , n);
        fill(i, j+1 , image, oldcolor, newcolor, m , n);
        fill(i, j-1 , image, oldcolor, newcolor, m , n);
        
        
        
        
        
    }
    
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        
        int oldcolor = image[sr][sc];
        
        // edge case
        if(oldcolor == newcolor)
            return image;
        
        
        fill(sr, sc , image,  oldcolor, newcolor, image[0].size() , image.size());
        return image;
        
    }
};