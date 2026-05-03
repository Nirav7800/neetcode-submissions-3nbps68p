class MinStack {
public:
    stack<long long>st;
    long long min_ele;
    MinStack() {
        min_ele = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            min_ele = val;
        } else {
            if(min_ele<=val){
                st.push(val);
            } else {
                st.push(2L*val-min_ele);
                min_ele = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        cout<<st.top()<<" "<<min_ele<<endl;
        if(st.top()>=min_ele) st.pop();
        else {
            min_ele = 2L*min_ele-st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        if(min_ele>st.top()) return min_ele;
        return st.top();
    }
    
    int getMin() {
        if(!st.empty()) return min_ele;
        return -1;
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