class DisJointSetUnion {
public:
    int n;
    vector<int> par, rank;
    DisJointSetUnion(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }
    void UnionByRank(int a, int b) {
        int parA = find(a);
        int parB = find(b);
        if (parA == parB) {
            return;
        }
        if (rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        } else if (rank[parA] > rank[parB]) {
            par[parB] = parA;
        } else {
            par[parA] = parB;
        }
    }
    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisJointSetUnion dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    dsu.UnionByRank(i, j);
                }
            }
        }
        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) {
                provinces++;
            }
        }
        return provinces;
    }
};