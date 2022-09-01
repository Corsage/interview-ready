class MinStack {
private:
    stack<pair<int,int>> s;
    int min;
public:
    
    MinStack() {
        min = numeric_limits<int>::max();
    }
    
    void push(int val) {
        if (val < min) {
            min = val;
        }
        
        s.push(make_pair(val, min));
    }
    
    void pop() {
        s.pop();
        min = s.empty() ? numeric_limits<int>::max() : s.top().second;
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */