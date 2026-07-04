class MinStack {
public:
    stack <int> st1;
    stack <int> st2;
    int mn = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        mn = min(mn, val);
        st2.push(mn);
    }
    
    void pop() {
        st1.pop();
        st2.pop();
        if(!st2.empty())
            mn = st2.top();
        else
            mn = INT_MAX;
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};
