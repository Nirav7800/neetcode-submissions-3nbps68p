class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int p1=0;
        int p2=n-1;
        while(p1<p2) {
            if(!isalpha(s[p1]) && !(s[p1]>='0' && s[p1]<='9')) {
                p1++;
            } else if(!isalpha(s[p2]) && !(s[p2]>='0' && s[p2]<='9')) {
                p2--;
            } else if(tolower(s[p1])!=tolower(s[p2])) {
                return false;
            } else {
                p1++;
                p2--;
            }
        }
        return true;
    }
};
