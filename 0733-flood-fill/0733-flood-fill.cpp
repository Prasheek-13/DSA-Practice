class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newcolor,
             int orignalcolor) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() ||
            image[sr][sc] != orignalcolor || image[sr][sc] == newcolor) {
            return;
        }
        image[sr][sc] = newcolor;
        dfs(image, sr - 1, sc, newcolor, orignalcolor);
        dfs(image, sr + 1, sc, newcolor, orignalcolor);
        dfs(image, sr, sc - 1, newcolor, orignalcolor);
        dfs(image, sr, sc + 1, newcolor, orignalcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int orignalcolor = image[sr][sc];
        dfs(image, sr, sc, color, orignalcolor);
        return image;
    }
};