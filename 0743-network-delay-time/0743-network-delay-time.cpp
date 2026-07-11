class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& t : times) {
            int u = t[0];
            int v = t[1];
            int wt = t[2];
            adj[u].push_back({v, wt});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});
        while (pq.size() > 0) {
            int u = pq.top().second;
            pq.pop();
            for (auto e : adj[u]) {
                int v = e.first;
                int wt = e.second;
                if (dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};