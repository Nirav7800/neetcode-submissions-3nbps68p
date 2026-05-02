class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto i:prerequisites){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        int completedCourse = 0;
        queue<int>q;
        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            completedCourse++;
            for(auto v:adj[curr]) {
                indegree[v]--;
                if(!indegree[v]) {
                    q.push(v);
                }
            }
        }
        return completedCourse==numCourses;
    }
};
