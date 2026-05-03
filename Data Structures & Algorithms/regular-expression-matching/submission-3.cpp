class Solution {
public:
    int dp[21][21];
    bool solve(string s,string p,int n1,int n2) {
        if(n1==0 && n2==0) {
            return true;
        }

        if(n2==0) return false;

        if(dp[n1][n2]!=-1) return dp[n1][n2];

        if(n1==0) {
            if(p[n2-1]=='*') return  dp[n1][n2]=solve(s,p,n1,n2-2);
            return false;
        }


        if(s[n1-1]==p[n2-1] || p[n2-1]=='.') {
            return  dp[n1][n2]=solve(s,p,n1-1,n2-1);
        } 
        else if(p[n2-1]=='*') {
            bool ans = solve(s,p,n1,n2-2); // skip "*"
            
            if(n2>=2 && (s[n1-1]==p[n2-2] || p[n2-2]=='.')) {
                ans |= solve(s,p,n1-1,n2); // consume char
            }
            return  dp[n1][n2]=ans;
        }

        return  dp[n1][n2]=false;
    }

    bool isMatch(string s, string p) {
        for(int i=0;i<=20;i++) {
            for(int j=0;j<=20;j++){
                dp[i][j]=-1;
            }
        }
        return solve(s,p,s.size(),p.size());
    }
};