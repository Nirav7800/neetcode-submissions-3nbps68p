class Solution {
public:
    string getpalindrom(string str,int s,int e, int n) {
        while(s>=0 && e<n && str[s]==str[e]) {
            s--;
            e++;
        }
        s++;
        e--;
        return str.substr(s,e-s+1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = s.substr(0,1);
        for(int i=1;i<n;i++) {

            //check for odd len
            string oddstr = s[i-1]==s[i+1]?getpalindrom(s,i-1,i+1,n):"";
            //check for even len
            string evenstr = s[i-1]==s[i]?getpalindrom(s,i-1,i,n):"";
            if(oddstr.size()>evenstr.size() && oddstr.size()>ans.size()) {
                ans = oddstr;
            } else if(oddstr.size()<evenstr.size() && evenstr.size()>ans.size()){
                ans = evenstr;
            }
            
        }
        return ans;
    }
};
