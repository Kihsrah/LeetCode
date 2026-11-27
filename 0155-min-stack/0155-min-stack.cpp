class MinStack {
public:
    int minStack[30000];
    int stack[30000];
    int TOP = -1;
    MinStack() {
        
    }
    
    void push(int value) {
        if (TOP == 30000 - 1) {
            return;
        } else {
            TOP++;
            stack[TOP] = value;
            if (TOP == 0) {
                minStack[TOP] = value;
            } else {
                minStack[TOP] = min(value, minStack[TOP - 1]);
            }
        }
    }
    
    void pop() {
        if (TOP == -1) {
            return;
        } else {
            TOP--;
        }
    }
    
    int top() {
        if (TOP == -1) {
            return NULL;
        } else {
            return stack[TOP];
        }
    }
    
    int getMin() {
        return minStack[TOP];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */