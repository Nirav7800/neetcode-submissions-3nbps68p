class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int>mp;
        for(auto t:tasks) {
            mp[t]++;
        }

        priority_queue<pair<int,char>>maxH;
        for(auto i:mp) {
            maxH.push({i.second,i.first});
        }

        int t=0;
        queue<pair<char,pair<int,int> >>q;
        while(!maxH.empty() || !q.empty()) {
          
            while(!q.empty() && q.front().second.first<=t) {
                    maxH.push({q.front().second.second,q.front().first});
                    q.pop();
             }
               t++;
            if(!maxH.empty()) {
                auto curr = maxH.top();
                maxH.pop();
                int count = curr.first;
                int ch = curr.second;
                count--;
                if(count) {
                    q.push({ch,{t+n,count}});
                }
            } 
        }
        return t;


    }
};
