class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int>col;
        unordered_set<int>row;
        int n = matrix.size();
        int m = matrix[0].size();
        int row_val = matrix[0][0];
        int col_val =  matrix[0][0];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j]==0) {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                    if(i==0) row_val = 0;
                    if(j==0) col_val = 0;
                }
            }
        }

        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                 if(matrix[i][0]==0 || matrix[0][j]==0) {
                    if(i==0 && row_val==0) { 
                           matrix[i][j]=0;
                     } else if(j==0 && col_val==0) {
                         matrix[i][j]=0;
                     } else if(i!=0 && j!=0) {
                            matrix[i][j]=0;
                     }
                   
                }
            }
        }
        
}
};
