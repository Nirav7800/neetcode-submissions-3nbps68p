class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        vector<int>freq(101,0);
         int first=INT_MIN, second = INT_MIN;
        for(auto i:stones) {
            freq[i]++;
            first = max(first,i);
        }
        second = first;
        while(first>0) {
            if(freq[first]%2==0) {
                freq[first]=0;
                first--;
                continue;
            }

            int ne = min(first-1,second);
            while(ne>0 && freq[ne]==0) ne--;
            if(ne==0) return first;
            second = ne;
            freq[first]--;
            freq[second]--;
            freq[first-second]++;
            first = max(second,first-second);
        }
        return first;
       

    }
};
