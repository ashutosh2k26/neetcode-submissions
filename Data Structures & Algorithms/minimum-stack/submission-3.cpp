class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        
        numS.push(val);

        if(minS.empty()) {
            minS.push(val);
        } else {
            if(val <= minS.top()){
                minS.push(val);
            }
        }
    }
    
    void pop() {
        int top = numS.top();
        if(top == minS.top()) {
            minS.pop();
        }
        numS.pop();
        
    }
    
    int top() {
        return numS.top();
    }
    
    int getMin() {
        return minS.top();
    }

    stack<int> minS;
    stack<int> numS;
};
