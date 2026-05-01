class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int r=0;
        int c=0;
        vector<int>ans;
        while(r<n && c<m) {
            //first row
            for(int i=c;i<m;i++) {
                ans.push_back(matrix[r][i]);
            }
            r++;
            //last col
            for(int i=r;i<n;i++) {
                ans.push_back(matrix[i][m-1]);
            }
            m--;
            if(r>=n || c>=m) return ans;
            //last row
            for(int i=m-1;i>=c;i--) {
                ans.push_back(matrix[n-1][i]);
            }
            n--;
            //first col
            for(int i=n-1;i>=r;i--) {
                ans.push_back(matrix[i][c]);
            }
            c++;
        }
        return ans;
    }
};
