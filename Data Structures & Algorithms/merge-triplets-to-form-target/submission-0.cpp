class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<int>curr={-1,-1,-1};
        for(int i=0; i<n;i++) {
            if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2]) {
                curr[0]=max(triplets[i][0],curr[0]);
                curr[1]=max(triplets[i][1],curr[1]);
                curr[2]=max(triplets[i][2],curr[2]);
            }
        }

        if(curr[0]==target[0] && curr[1]==target[1] && curr[2]==target[2]){
            return true;
        }
        return false;
    }
};
