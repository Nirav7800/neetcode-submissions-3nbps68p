class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        unordered_map<char,set<char>>mp;
        unordered_map<char,int>indegree;
        for(auto w:words) {
            for(auto c:w) indegree[c]=0;
        }
        for(int i=0;i<n-1;i++) {
            string s1 = words[i];
            string s2 = words[i+1];
            int p1 = 0;
            int p2 = 0;
            while(p1<s1.size() && p2<s2.size()) {
                if(s1[p1]!=s2[p2]) {
                    if(mp[s1[p1]].find(s2[p2])==mp[s1[p1]].end()) indegree[s2[p2]]++;
                    mp[s1[p1]].insert(s2[p2]);
                    break;
                }
                p1++;
                p2++;
            }  

            // 🔴 missing edge case
            if(p1 < s1.size() && p2 == s2.size()) return "";
        }

        queue<char>q;
        for(auto c:indegree) {
            if(c.second==0) q.push(c.first);
        }
        string ans = "";

        while(!q.empty()) {
            char curr = q.front();
            q.pop();
            ans+=curr;
            for(auto v:mp[curr]) {
              
                    indegree[v]--;
                    if(indegree[v]==0) {
                        q.push(v);
                    }
            }
        }
        for(auto i:indegree) {
            if(i.second!=0) return "";
        }
        return ans;
    }
};
