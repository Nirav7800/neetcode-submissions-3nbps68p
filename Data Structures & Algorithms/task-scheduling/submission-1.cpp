class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int max_freq=1;
        for(auto t:tasks){
            mp[t]++;
            max_freq=max(mp[t],max_freq);
        }
        int count = 0;
        for(auto i:mp) {
            if(max_freq==i.second) {
                count++;
            }
        }
        int time = (max_freq-1)*(n+1)+count;
        return max((int)tasks.size(),time);
    }
};
