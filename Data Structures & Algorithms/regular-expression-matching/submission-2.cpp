class Solution {
public:
    bool solve(string s,string p,int n1,int n2) {
        if(n1==0 && n2==0) {
            return true;
        }

        if(n2==0) return false;

        if(n1==0) {
            if(p[n2-1]=='*') return solve(s,p,n1,n2-2);
            return false;
        }

        if(s[n1-1]==p[n2-1] || p[n2-1]=='.') {
            return solve(s,p,n1-1,n2-1);
        } 
        else if(p[n2-1]=='*') {
            bool ans = solve(s,p,n1,n2-2); // skip "*"
            
            if(n2>=2 && (s[n1-1]==p[n2-2] || p[n2-2]=='.')) {
                ans |= solve(s,p,n1-1,n2); // consume char
            }
            return ans;
        }

        return false;
    }

    bool isMatch(string s, string p) {
        return solve(s,p,s.size(),p.size());
    }
};