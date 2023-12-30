class Solution {
    void solve(vector<vector<int>>& image, int i, int j, int color, int pixel) {
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != pixel) {
            return;
        }

        image[i][j] = color;

        solve(image, i, j+1, color, pixel);
        solve(image, i, j-1, color, pixel);
        solve(image, i+1, j, color, pixel);
        solve(image, i-1, j, color, pixel);
    }

    public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image;  // If new color is same as current color, no need to do anything
        }

        solve(image, sr, sc, color, image[sr][sc]);

        return image;
    }
};