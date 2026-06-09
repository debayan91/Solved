class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int org) {
        if(i < 0 || i >= size(image) || j < 0 || j >= size(image[0]) || image[i][j] != org) return;
        image[i][j] = color;
        dfs(image, i + 1, j, color, org);
        dfs(image, i - 1, j, color, org);
        dfs(image, i, j + 1, color, org);
        dfs(image, i, j - 1, color, org);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        if(color == image[sr][sc]) return image;
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};