class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char,int>mp;//store last pos of the char in the string
        for(int i=0;i<n;i++) {
            mp[s[i]]=i;
        }
        vector<int>ans;
        int start = 0;
        int end = mp[s[0]];
        for(int i=0;i<n;i++) {
            if(end==i) {
                ans.push_back(end-start+1);
                start=i+1;
                if(i+1!=n)
                end = mp[s[i+1]];
            }else {
                end = max(end,mp[s[i]]);
            }
        }
        return ans;
    }
};
