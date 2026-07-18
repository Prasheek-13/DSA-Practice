class Solution {
public:
    vector<int> par;
    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            par[i] = i;
        }
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int parU = find(u);
            int parV = find(v);
            if (parU == parV) {
                return {u, v};
            }
            par[parV] = parU;
        }
        return {};
    }
};