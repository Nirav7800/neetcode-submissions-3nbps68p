class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mp;
    vector<string> ans;

    void dfs(string src) {
        while (!mp[src].empty()) {
            string next = mp[src].top();
            mp[src].pop();
            dfs(next);
        }
        ans.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto &t : tickets)
            mp[t[0]].push(t[1]);

        dfs("JFK");

        reverse(ans.begin(), ans.end());
        return ans;
    }
};