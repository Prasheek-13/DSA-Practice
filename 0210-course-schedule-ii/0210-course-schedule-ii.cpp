class Solution {
public:
    bool dfs(int curr, vector<bool>& vis, vector<bool>& recpath,
             vector<vector<int>>& adj, stack<int>& s) {
        vis[curr] = true;
        recpath[curr] = true;
        for (int v : adj[curr]) {
            if (!vis[v]) {
                if (dfs(v, vis, recpath, adj, s)) {
                    return true;
                }
            } else if (recpath[v]) {
                return true;
            }
        }
        s.push(curr);
        recpath[curr] = false;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        vector<bool> vis(n, false);
        vector<bool> recpath(n, false);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, recpath, adj, s)) {
                    return {};
                }
            }
        }
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};