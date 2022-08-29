class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int i = 0;
        int n = nums.size();
        
         int j = n -1;
        
     
        
        
        vector<int> vec(n, 0);
         int  k = n-1;
         
        
        
        
        while( i <= j ){
            
            if( abs(nums[i]) > abs(nums[j])){
                
                vec[k--]= nums[i]*nums[i];
                i++;
                     
            }
            else{
                
                 
                vec[k--] = nums[j]*nums[j];
                
                 j--;
        
            }
            
            
        }
        return vec;
        
        
    }
};