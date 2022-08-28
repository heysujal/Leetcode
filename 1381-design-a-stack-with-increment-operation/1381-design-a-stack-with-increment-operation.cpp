class CustomStack {
    
     
    int top;
    int *arr;
    int maxSize;
    
    
public:
     
    
    CustomStack(int maxSize) {
         top = -1;
         this->maxSize = maxSize;
         arr = new int[maxSize];
        
    }
    
    void push(int x) {
        if(maxSize!=top+1)
        {   
            top++;
            arr[top]= x;
        }
    }
    
    int pop() {
        
      if(top!=-1)
      {
          return arr[top--];
      }
        return -1;
        
        
    }
    
    void increment(int k, int val) {
        
        
        if(top+1 >= k)
        {
            for(int i= 0 ; i < k ; i++)
            {
                arr[i]+=val;
            }
        }
        else{
            int i = 0;
            while(i<=top)
            {
                arr[i]+=val;
                i++;
            }
            
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */