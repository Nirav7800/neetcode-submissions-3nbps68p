class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return false;
        unordered_map<int,int>mp;
        for(auto i:hand) {
            mp[i]++;
        }
        sort(hand.begin(),hand.end());
        for(auto i:hand) {
            int count = groupSize-1;
            if(mp[i]==0) {
                mp.erase(i);
                continue;
            }
            int curr = i+1;
            while(count>0 && mp.count(curr) && mp[curr]>=mp[i]) {
                mp[curr]-=mp[i];
                curr++;
                count--;
            }
            if(count) return false;
            mp.erase(i);
        
        }
        return mp.size()==0;
    }
};
