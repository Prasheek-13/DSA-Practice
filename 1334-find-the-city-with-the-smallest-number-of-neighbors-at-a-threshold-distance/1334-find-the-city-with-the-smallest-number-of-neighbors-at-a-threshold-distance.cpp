class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for (int u = 0; u < n; u++) {
            for (auto edge : adj[u]) {
                int v = edge.first;
                int wt = edge.second;
                dist[u][v] = wt;
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] == INF || dist[k][j] == INF)
                        continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int city = -1;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {

            int cnt = 0;

            for (int j = 0; j < n; j++) {

                if (i != j && dist[i][j] <= distanceThreshold)
                    cnt++;
            }

            if (cnt <= mini) {
                mini = cnt;
                city = i;
            }
        }

        return city;
    }
};