class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = 0;
        int hi = n*m-1;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            int r = mid/m;
            int c = mid%m;
            int ele = matrix[r][c];
            if(ele==target) {
                return true;
            } else if(ele > target) {
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return false;
    }
};
