class CountSquares {
public:
    unordered_map<string,int>mp;
    int max_x;
    int max_y;
    CountSquares() {
        mp.clear();
        max_x = 0;
        max_y = 0;
    }
    
    void add(vector<int> point) {
       string key = to_string(point[0]) + "," + to_string(point[1]);
        max_x = max(point[0],max_x);
        max_y = max(point[1],max_y);
        mp[key]++;
    }
    
    int count(vector<int> point) {
    int x = point[0], y = point[1];
    int ans = 0;

    // existing loop 1: tx < x, ty > y
    for (int tx = x-1, ty = y+1; tx >= 0 && ty <= max_y; tx--, ty++) {
        string p2 = to_string(tx)+","+to_string(ty);
        string p3 = to_string(x) +","+to_string(ty);
        string p4 = to_string(tx)+","+to_string(y);
        if (mp.count(p2) && mp.count(p3) && mp.count(p4))
            ans += mp[p2] * mp[p3] * mp[p4];
    }

    // existing loop 2: tx > x, ty < y
    for (int tx = x+1, ty = y-1; tx <= max_x && ty >= 0; tx++, ty--) {
        string p2 = to_string(tx)+","+to_string(ty);
        string p3 = to_string(x) +","+to_string(ty);
        string p4 = to_string(tx)+","+to_string(y);
        if (mp.count(p2) && mp.count(p3) && mp.count(p4))
            ans += mp[p2] * mp[p3] * mp[p4];
    }

    // FIX loop 3: tx < x, ty < y
    for (int tx = x-1, ty = y-1; tx >= 0 && ty >= 0; tx--, ty--) {
        string p2 = to_string(tx)+","+to_string(ty);
        string p3 = to_string(x) +","+to_string(ty);
        string p4 = to_string(tx)+","+to_string(y);
        if (mp.count(p2) && mp.count(p3) && mp.count(p4))
            ans += mp[p2] * mp[p3] * mp[p4];
    }

    // FIX loop 4: tx > x, ty > y
    for (int tx = x+1, ty = y+1; tx <= max_x && ty <= max_y; tx++, ty++) {
        string p2 = to_string(tx)+","+to_string(ty);
        string p3 = to_string(x) +","+to_string(ty);
        string p4 = to_string(tx)+","+to_string(y);
        if (mp.count(p2) && mp.count(p3) && mp.count(p4))
            ans += mp[p2] * mp[p3] * mp[p4];
    }

    return ans;
}
};
