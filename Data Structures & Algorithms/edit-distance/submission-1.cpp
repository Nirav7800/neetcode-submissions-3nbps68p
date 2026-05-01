class Solution {
public:
    int dp[101][101];
    int solve(string word1,string word2,int n1,int n2) {
        if(n2==0 || n1==0) {
            return max(n1,n2);
        }

        if(dp[n1][n2]!=-1) return dp[n1][n2];
        if(word1[n1-1]==word2[n2-1]) {
            return solve(word1,word2,n1-1,n2-1);
        }

        //insert
        int ic = 1+solve(word1,word2,n1,n2-1);

        //delete
        int dc = 1+solve(word1,word2,n1-1,n2);

        int rc = 1+solve(word1,word2,n1-1,n2-1);

        return dp[n1][n2]=min(ic,min(dc,rc));
    } 
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        for(int i=0;i<=n1;i++) {
            for(int j=0;j<=n2;j++) {
                dp[i][j]=-1;
            }
        }
        return solve(word1,word2,n1,n2);
    }
};
