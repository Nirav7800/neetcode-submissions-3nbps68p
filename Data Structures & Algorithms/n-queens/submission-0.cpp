class Solution {
public:

    void solve(int n,int row,unordered_set<int>&dia1,unordered_set<int>&dia2, unordered_set<int>&col,vector<string>&curr, vector<vector<string>>&ans) {
        if(row==n) {
            ans.push_back(curr);
            return;
        }
        for(int c=0;c<n;c++) {
            if(!dia1.count((row-c)) && !dia2.count(abs(row+c)) && !col.count(c)){
                cout<<row<<" "<<c<<endl;
                curr[row][c]='Q';
                col.insert(c);
                dia1.insert((row-c));
                dia2.insert(abs(row+c));
                solve(n,row+1,dia1,dia2,col,curr,ans);
                col.erase(c);
                dia1.erase((row-c));
                dia2.erase(abs(row+c));
                curr[row][c]='.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int>col;
          unordered_set<int>dia1;
          unordered_set<int>dia2;
        vector<string>curr;
        for(int i=0;i<n;i++) {
            string temp ="";
            for(int j=0;j<n;j++) {temp+=".";
            }
            curr.push_back(temp);
        }
        vector<vector<string>>ans;
        solve(n,0,dia1,dia2,col,curr,ans);
        return ans;
    }
};
