class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int>col;
        unordered_set<int>row;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j]==0) {
                    col.insert(j);
                    row.insert(i);
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(col.count(j) || row.count(i)) {
                   matrix[i][j]=0;
                }
            }
        }
        
}
};
