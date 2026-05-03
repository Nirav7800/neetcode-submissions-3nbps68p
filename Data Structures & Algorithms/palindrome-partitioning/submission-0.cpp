class Solution {
public:
    bool ispalindrom(string s) {
        int i=0,j=s.size()-1;

        while(i<j) {
            if(s[i]!=s[j]) {
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    void solve(string s, int start, int n,vector<string>curr, vector<vector<string>>&ans) {
        if(start==n) {
            ans.push_back(curr);
            return;
        }

        for(int i=start;i<n;i++) {
            string currString = s.substr(start,i-start+1);
            if(ispalindrom(currString)) {
                curr.push_back(currString);
                solve(s,i+1,n,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<string>curr;
        vector<vector<string>>ans;
        solve(s,0,n,curr,ans);

        return ans;
    }
};