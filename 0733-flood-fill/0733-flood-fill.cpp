class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newcolor,
             int originalcolor) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() ||
            image[sr][sc] != originalcolor || image[sr][sc] == newcolor) {
            return;
        }
        image[sr][sc] = newcolor;
        dfs(image, sr - 1, sc, newcolor, originalcolor);
        dfs(image, sr + 1, sc, newcolor, originalcolor);
        dfs(image, sr, sc - 1, newcolor, originalcolor);
        dfs(image, sr, sc + 1, newcolor, originalcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int oricolor = image[sr][sc];
        dfs(image, sr, sc, color, oricolor);
        return image;
    }
};