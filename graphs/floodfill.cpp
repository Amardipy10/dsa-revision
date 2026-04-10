class Solution {
public:

    void dfs(int i, int j, vector<vector<int>>& image, int oldColor, int newColor) {
        int n = image.size();
        int m = image[0].size();

        // boundary + color check
        if(i < 0 || j < 0 || i >= n || j >= m || image[i][j] != oldColor) {
            return;
        }

        image[i][j] = newColor;

        dfs(i-1, j, image, oldColor, newColor);
        dfs(i, j+1, image, oldColor, newColor);
        dfs(i+1, j, image, oldColor, newColor);
        dfs(i, j-1, image, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];

        // edge case
        if(oldColor == color) return image;

        dfs(sr, sc, image, oldColor, color);

        return image;
    }
};