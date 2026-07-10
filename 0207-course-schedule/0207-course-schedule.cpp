class Solution {
public:
    bool toposort(vector<vector<int>>& adj) {
        // calculate indgree
        vector<int> res;
        vector<int> indeg(adj.size(), 0);
        for (int u = 0; u < adj.size(); u++) {
            for (int v : adj[u]) {
                indeg[v]++;
            }
        }
        // 0 indeg ==> Q
        queue<int> q;
        for (int i = 0; i < indeg.size(); i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        // bfs
        while (q.size() > 0) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for (int v : adj[curr]) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        // result
        if (res.size() != adj.size()) {
            return false;
        }
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& p : edges) {
            adj[p[1]].push_back(p[0]);
        };
        return toposort(adj);
    }
};