class FreqStack {
    

public:

    unordered_map<int,int>count;
    unordered_map<int,stack<int>>st;
    int maxcount;
    FreqStack() {
        maxcount=0;
        
    }
    
    void push(int val) {
        int valcount = ++count[val];
        if(valcount>maxcount)
        {
            maxcount=valcount;
            st[valcount]=stack<int>();
        }
        st[valcount].push(val);
        
    }
    
    int pop() {
        int result = st[maxcount].top();
        st[maxcount].pop();
        count[result]--;
        if(st[maxcount].empty())
        {
            maxcount--;
        }
        
        return result;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */