class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int wt = abs(points[i][0] - points[j][0]) +
                         abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }
        int V = adj.size();
        vector<bool> InMST(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        int mstcost = 0;
        while (!pq.empty()) {
            auto p = pq.top();
            int wt = p.first;
            int u = p.second;
            pq.pop();
            if (!InMST[u]) {
                InMST[u] = true;
                mstcost = wt + mstcost;
                for (int i = 0; i < adj[u].size(); i++) {
                    int v = adj[u][i].first;
                    int w = adj[u][i].second;
                    if (!InMST[v]) {
                        pq.push({w, v});
                    }
                }
            }
        }
        return mstcost;
    }
};