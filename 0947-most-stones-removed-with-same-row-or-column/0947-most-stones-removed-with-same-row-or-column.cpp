class Solution {
public:
    vector<int> par;
    vector<int> rank;
    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }
    void unionD(int a, int b) {
        int para = find(a);
        int parb = find(b);
        if (para == parb)
            return;
        if (rank[para] == rank[parb]) {
            par[parb] = para;
            rank[para]++;
        } else if (rank[para] > rank[parb]) {
            par[parb] = para;

        } else {
            par[para] = parb;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        par.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    unionD(i, j);
                }
            }
        }
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) {
                components++;
            }
        }
        return n - components;
    }
};