class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), -1));
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    vis[i][j] = true;
                    q.push({{i, j}, 0});
                    ans[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            if (i - 1 >= 0 && !vis[i - 1][j]) {
                vis[i - 1][j] = true;
                ans[i - 1][j] = dist + 1;
                q.push({{i - 1, j}, dist + 1});
            }
            if (i + 1 < n && !vis[i + 1][j]) {
                vis[i + 1][j] = true;
                ans[i + 1][j] = dist + 1;
                q.push({{i + 1, j}, dist + 1});
            }
            if (j - 1 >= 0 && !vis[i][j - 1]) {
                vis[i][j - 1] = true;
                ans[i][j - 1] = dist + 1;
                q.push({{i, j - 1}, dist + 1});
            }
            if (j + 1 < m && !vis[i][j + 1]) {
                vis[i][j + 1] = true;
                ans[i][j + 1] = dist + 1;
                q.push({{i, j + 1}, dist + 1});
            }
        }
        return ans;
    }
};