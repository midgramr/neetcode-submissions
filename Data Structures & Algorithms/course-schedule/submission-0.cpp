class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // If can be finished, graph is DAG
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses);

        for (auto edge : prerequisites) {
            int src = edge[1], dst = edge[0];
            indeg[dst]++;
            adj[src].push_back(dst);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int i = q.front(); q.pop();
            for (auto neighbor : adj[i]) {
                indeg[neighbor]--;
                if (indeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] > 0) return false;
        }
        return true;
    }
};
