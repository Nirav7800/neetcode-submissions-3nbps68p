class CountSquares {
public:
    unordered_map<int,unordered_map<int,int>>mp; // [x][y]->count;
    vector<vector<int>> pts;
    CountSquares() {
        mp.clear();
    }
    
    void add(vector<int> point) {
       mp[point[0]][point[1]]++;
       pts.push_back(point);
    }
    
    int count(vector<int> point) {
    int ans = 0;
    int x = point[0];
    int y = point[1];
    for(auto pt:pts) {
        int nx = pt[0];
        int ny = pt[1];
        if(abs(nx-x)!=abs(ny-y) || x==nx || y==ny) continue;
        ans +=mp[x][ny]*mp[nx][y];
    }

    return ans;
}
};
