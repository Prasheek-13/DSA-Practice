class Solution {
public:
    bool toposort(int curr, vector<bool>& vis, vector<bool>& recpath,
                  stack<int>& s, vector<vector<int>>& adj) {
        vis[curr] = true;
        recpath[curr] = true;
        for (int v : adj[curr]) {
            if (!vis[v]) {
                if (toposort(v, vis, recpath, s, adj))
                    return true;
            } else if (recpath[v]) {
                return true;
            }
        }
        recpath[curr] = false;
        s.push(curr);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        vector<bool> vis(numCourses, false);
        vector<bool> recpath(numCourses, false);
        stack<int> s;
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (toposort(i, vis, recpath, s, adj)) {
                    return {};
                }
            }
        }
        vector<int> ans;
        while (!s.empty()) {
            int curr = s.top();
            s.pop();
            ans.push_back(curr);
        }
        return ans;
    }
};