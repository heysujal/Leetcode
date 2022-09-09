class Solution {
public:
    int fib(int n) {
        if(n<=1)
            return n;
        
        int f = 0;
        int s= 1;
        
        for(int i = 2; i <= n; i++)
        {
            int sum = f+s;
            f = s;
            s= sum;
            
        }
        return s;
        
    }
};