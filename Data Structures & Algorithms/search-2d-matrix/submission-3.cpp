class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        //get the row
        int lo = 0;
        int hi = n-1;
        int col = m-1;
        if(n==1 && m==1) {
            return matrix[0][0]==target;
        }
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(matrix[mid][col]==target) {
                return true;
            } else if(matrix[mid][col]<target) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }

        int row = lo;
        if (row >= n) return false;
        lo = 0;
        hi = m-1;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(matrix[row][mid]==target) {
                return true;
            } else if(matrix[row][mid]<target) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return false;
    }
};
