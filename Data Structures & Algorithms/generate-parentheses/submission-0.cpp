class Solution {
public:
    void solve(int oc,int cc,int n,string curr,vector<string>&ans) {
        if(cc==n && oc==n) {
            ans.push_back(curr);
            return;
        }

        if(oc<n){
            solve(oc+1,cc,n,curr+"(",ans);
        }
        if(cc<oc){
            solve(oc,cc+1,n,curr+")",ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(0,0,n,"",ans);
        return ans;
    }
};
