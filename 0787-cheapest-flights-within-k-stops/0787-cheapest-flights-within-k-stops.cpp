class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        // vector<vector<pair<int,int>>> adj(n);
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;
            for (auto& p : flights) {
                int u = p[0];
                int v = p[1];
                int wt = p[2];
                if (dist[u] == INT_MAX)
                    continue;
                if (temp[v] > dist[u] + wt) {
                    temp[v] = dist[u] + wt;
                }
            }
            dist = temp;
        }

        if (dist[dst] == INT_MAX) {
            return -1;
        }
        return dist[dst];
    }
};