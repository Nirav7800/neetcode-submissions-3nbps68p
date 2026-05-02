class Solution {
public:
    bool checkValidString(string s) {
        stack<char>s1;
        stack<char>s2;
        int n = s.size();
        for(int i=0;i<n;i++) {
            if(s[i]=='*') {
                s1.push(i);
            } else if(s[i]=='(') {
                s2.push(i);
            } else {
                if(!s2.empty()){
                    s2.pop();
                }else if(!s1.empty()) {
                    s1.pop();
                } else {
                    return false;
                }

            }
        }
        while(!s2.empty() && !s1.empty()) {
            if(s1.top()>s2.top()) {
                s1.pop();
                s2.pop();
            } else {
                return false;
            }
        }
        return s2.empty();
    }
};
