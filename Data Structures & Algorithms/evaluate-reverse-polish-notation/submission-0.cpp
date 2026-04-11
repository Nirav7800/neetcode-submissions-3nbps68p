class Solution {
public:
    bool isop(string s) {
        return s=="+"||s=="-"||s=="*"||s=="/";
    }
    int eval(int a,int b,string op) {
        if(op=="+") return a+b;
        if(op=="-") return a-b;
        if(op=="*") return a*b;
        return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto s:tokens) {
            if(isop(s)) {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(eval(a,b,s));
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
