class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int curr =0;
        int idx = 0;
         int totalCOst = 0;
        int totalFuel = 0;
        for(int i=0;i<n;i++){
            curr+=(gas[i]-cost[i]);
            if(curr<0) {
                curr=0;
                idx=i+1;
            }
             totalCOst+=cost[i];
            totalFuel+=gas[i];
        }
        return totalCOst>totalFuel?-1:idx;
    }
};
