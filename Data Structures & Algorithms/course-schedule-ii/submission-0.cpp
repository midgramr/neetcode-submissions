class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses);

        for (auto edge : prerequisites) {
            int src = edge[1], dst = edge[0];
            indeg[dst]++;
            adj[src].push_back(dst);
        }

        vector<int> order;
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int i = q.front(); q.pop();
            order.push_back(i);
            for (auto nei : adj[i]) {
                indeg[nei]--;
                if (indeg[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] > 0) return {};
        }
        return order;
    }
};
