class Solution {
public:
    bool dfs(int curr, vector<bool>& vis, vector<bool>& recpath,
             vector<vector<int>>& adj) {
        vis[curr] = true;
        recpath[curr] = true;
        // for (int i = 0; i < edges.size(); i++) {
        //     int u = edges[i][1];
        //     int v = edges[i][0];
        //     if (curr == u) {
        //         if (!vis[v]) {
        //             if (dfs(v, vis, recpath, edges)) {
        //                 return true;
        //             }
        //         } else if (recpath[v]) {
        //             return true;
        //         }
        //     }
        // }
        for (int v : adj[curr]) {
            if (!vis[v]) {
                if (dfs(v, vis, recpath, adj)) {
                    return true;
                }
            } else if (recpath[v]) {
                return true;
            }
        }
        recpath[curr] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& p : edges) {
            adj[p[1]].push_back(p[0]);
        };
        vector<bool> vis(n, false);
        vector<bool> recpath(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, recpath, adj)) {
                    return false;
                }
            }
        }
        return true;
    }
};