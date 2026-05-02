class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxH;
        for(auto i:stones) {
            maxH.push(i);
        }
        while(maxH.size()>=2) {
            int f = maxH.top();
            maxH.pop();
            int s = maxH.top();
            maxH.pop();
            if(f!=s) {
                maxH.push(f-s);
            }
        }
        if(maxH.size()) return maxH.top();
        return 0;
    }
};
