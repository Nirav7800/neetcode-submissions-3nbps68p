class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        //construct the adj vector

        vector<vector<int>> adj(numCourses);
       vector<int>indegree(numCourses,0);

        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int>q;
        for(int i = 0;i<numCourses;i++) {
            if(indegree[i]==0) q.push(i);
        }
        vector<int>path;

        while(!q.empty()) {

            int curr= q.front();
            q.pop();

            path.push_back(curr);

            for(int i = 0; i<(adj[curr]).size(); i++) {
                indegree[adj[curr][i]]--;
                if(indegree[adj[curr][i]]==0) q.push(adj[curr][i]);
            }
        }
         for(int i = 0;i<numCourses;i++) {
            if(indegree[i]!=0) return {};
        }
        return path;


        
    }
};