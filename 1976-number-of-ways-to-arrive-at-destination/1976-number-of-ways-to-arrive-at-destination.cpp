class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for (auto edges : roads) {
            int u = edges[0];
            int v = edges[1];
            int wt = edges[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        vector<int> ways(n, 0);
        ways[0] = 1;
        priority_queue<pair<long, long>, vector<pair<long, long>>,
                       greater<pair<long, long>>>
            pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (d > dist[u]) {
                continue;
            }
            for (auto edge : adj[u]) {
                int v = edge.first;
                int wt = edge.second;
                if (dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                     ways[v] = ways[u];
                }
                 else if (dist[u] + wt == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};