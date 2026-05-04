class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(auto c:s1) {
            mp1[c]++;
        }

        int count=0;
        int p1=0;
        int p2=0;
        int n = s2.size();
        int m = s1.size();
        if(n<m) {
            return false;
        }
        while(p2<m) {
           mp2[s2[p2]]++;
           if(mp1.count(s2[p2])) {
             if(mp2[s2[p2]]==mp1[s2[p2]]){
                count++;
             } else if(mp2[s2[p2]]==mp1[s2[p2]]+1){
                count--;
             }
           }
           p2++;
        }
        if(count==mp1.size()) {
            return true;
        }

        while(p2<n) {
            mp2[s2[p2]]++;
            if(mp1.count(s2[p2])) {
             if(mp2[s2[p2]]==mp1[s2[p2]]){
                count++;
             } else if(mp2[s2[p2]]==mp1[s2[p2]]+1){
                count--;
             }
           }
           mp2[s2[p1]]--;
             if(mp1.count(s2[p1])) {
                if(mp2[s2[p1]]==mp1[s2[p1]]-1){
                    count--;
                }else if(mp2[s2[p1]]==mp1[s2[p1]]){
                    count++;
                }
             } 
            p1++;
            p2++;
            if(count==mp1.size()) {
            return true;
            }
        }
        return false;

    }
};
