class Solution {
public:
    bool dfs(int curr, vector<bool>& vis, vector<bool>& recpath,
             vector<vector<int>>& edges) {
        vis[curr] = true;
        recpath[curr] = true;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][1];
            int v = edges[i][0];
            if (curr == u) {
                if (!vis[v]) {
                    if (dfs(v, vis, recpath, edges)) {
                        return true;
                    }
                } else if (recpath[v]) {
                    return true;
                }
            }
        }
        recpath[curr] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> recpath(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, recpath, edges)) {
                    return false;
                }
            }
        }
        return true;
    }
};