class Solution {
public:

    bool canMoveForward(vector<vector<int>>& image, int i, int j, int n, int m, int oldcolor) {

        //if it is not exceeding boundaries and cell is old colored
        if (i>=0 && i<n && j>=0 && j<m && (image[i][j]==oldcolor))
            return true;
        return false;
    }

    void floodFillHelper(vector<vector<int>>& image, int i, int j, int n, int m,  int oldcolor, int color) {

        //change color to new color
        image[i][j] = color;

        if (canMoveForward(image, i+1, j, n, m, oldcolor)) {
            floodFillHelper(image, i+1, j, n, m, oldcolor, color);
        }
        if (canMoveForward(image, i-1, j, n, m, oldcolor)) {
            floodFillHelper(image, i-1, j, n, m, oldcolor, color);
        }
        if (canMoveForward(image, i, j+1, n, m, oldcolor)) {
            floodFillHelper(image, i, j+1, n, m, oldcolor, color);
        }
        if (canMoveForward(image, i, j-1, n, m, oldcolor)) {
            floodFillHelper(image, i, j-1, n, m, oldcolor, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        int oldcolor;

        if (sr < n && sc < m)
            oldcolor = image[sr][sc];
        else
            return image;

        //if it is already colored to a new color, no need to proceed. Without this check the program fails
        if (oldcolor == color)
            return image;

        floodFillHelper(image, sr, sc, n, m, oldcolor, color);
        
        return image;
    }
};
