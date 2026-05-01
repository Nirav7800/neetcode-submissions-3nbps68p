class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>mp;
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                if(board[i][j]!='.') {
                    string rowKey = to_string(i)+"row"+to_string(board[i][j]);
                    string colKey = to_string(j)+"col"+to_string(board[i][j]);
                    string box = to_string(i/3)+"box"+to_string(j/3)+"box"+to_string(board[i][j]);
                    if(mp.count(rowKey) || mp.count(colKey) || mp.count(box)) return false;
                    mp.insert(rowKey);
                    mp.insert(colKey);
                    mp.insert(box);
                }
            }
        }
        return true;
    }
};
