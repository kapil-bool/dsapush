class Solution {
public:
    int rown[4] = {-1, 1, 0, 0};
    int coln[4] = {0, 0, -1, 1};

    bool isvalid(int i, int j, int row, int col) {
        return i >= 0 && i < row && j >= 0 && j < col;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int n, int m, int color, int orignalcolur) {
        image[sr][sc] = color;
        for (int i = 0; i < 4; i++) {
            int new_r = sr + rown[i];
            int new_c = sc + coln[i];
            if (isvalid(new_r, new_c, n, m) and image[new_r][new_c] == orignalcolur) {
                dfs(image, new_r, new_c, n, m, color, orignalcolur);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int orignalcolur = image[sr][sc];
        if (orignalcolur != color) {
            dfs(image, sr, sc, n, m, color, orignalcolur);
        }
        return image;
    }
};
