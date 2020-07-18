class MinStack {
public:
    int minValue;
    stack<int> normalStack;
    stack<int> minStack;
    /** initialize your data structure here. */
    MinStack() {
        minValue = INT_MAX;
    }
    
    void push(int x) {
        if (minStack.empty())
            minStack.push(x);
        else if (x <= minStack.top()) {
            minStack.push(x);
        } 
            
        normalStack.push(x);
    }
    
    void pop() {
        if (minStack.empty())
            return;
        if (minStack.top() == normalStack.top()) {
            minStack.pop();
            normalStack.pop();
        }
        else 
            normalStack.pop();
    }
    
    int top() {
        return normalStack.top();
    }
    
    int getMin() {
        return minStack.top();
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