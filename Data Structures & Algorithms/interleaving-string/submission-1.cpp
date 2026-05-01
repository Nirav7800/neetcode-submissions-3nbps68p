class Solution {
public:
    int dp[201];
    bool solve(string s1, string s2, string s3,int n1,int n2,int n3){
        if(n3==0) {
            return true;
        }
        bool ans = false;
        if(dp[n3]!=-1) return dp[n3];
        if(s1[n1-1]==s3[n3-1]) {
            ans = solve(s1,s2,s3,n1-1,n2,n3-1);
        }

        if(s2[n2-1]==s3[n3-1]) {
            ans|=solve(s1,s2,s3,n1,n2-1,n3-1);
        }
        return dp[n3]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        for(int i=0;i<=200;i++) dp[i]=-1;
        if(n1+n2!=n3) {
            return false;
        }
        return solve(s1,s2,s3,n1,n2,n3);
    }
};
