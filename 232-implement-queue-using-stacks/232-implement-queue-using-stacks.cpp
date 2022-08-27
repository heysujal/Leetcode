class MyQueue {
public:
     stack<int> s; 
    MyQueue() {
      
    }
    
    void push(int x) {
        vector<int> temp;
        
        while(!s.empty())
        {
            temp.push_back(s.top());
            s.pop();
            
        }
        
        s.push(x);
        
        for(int i = temp.size() -1 ; i >=0 ; i--)
        {
            s.push(temp[i]);
        }
    }
    
    int pop() {
        
        
        if(!s.empty())
        {
            int val = s.top();
            s.pop();
            return val;
            
        }
        return -1;
        
    }
    
    int peek() {
        
       if(!s.empty()) 
            return s.top();
        return -1;
        
    }
    
    bool empty() {
        
        if(!s.empty())
            return false;
        return true;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */