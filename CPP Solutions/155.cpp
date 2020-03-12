class MinStack {
private:
    stack<int> mins;
    stack<int> nums;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        nums.push(x);
        if (mins.empty() || x <= getMin()) {
            mins.push(x);
        }
    }
    
    void pop() {
        int val = nums.top();
        nums.pop();
        if (val == getMin()) {
            mins.pop();
        }
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */