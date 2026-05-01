class Solution {
public:
    void solve(string& digits,int i, string curr, vector<string>&ans,unordered_map<char,string>&mp) {
        if(i==digits.size()) {
            ans.push_back(curr);
            return;
        }
        for(auto c:mp[digits[i]]) {
            solve(digits,i+1,curr+c,ans,mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        vector<string>ans;
        if(!digits.size()) return ans;
        solve(digits,0,"",ans,mp);
        return ans;
    }
};
