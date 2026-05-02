class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        //reverse col
        for(int i=0;i<m;i++) {
            int p1 =0;
            int p2 = n-1;
            while(p1<p2){
                swap(matrix[p1][i],matrix[p2][i]);
                p1++;
                p2--;
            }
        }
        //swap i and j
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

    }
};
