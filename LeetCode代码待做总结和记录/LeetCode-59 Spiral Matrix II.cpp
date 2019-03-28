/*需要与Spiral Matrix的第二种方法结合着看*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        int val = 1, p = n;
        for (int i = 0; i < n / 2; ++i, p -= 2) {
            for (int col = i; col < i + p; ++col)
                res[i][col] = val++;
            for (int row = i + 1; row < i + p; ++row)
                res[row][i + p - 1] = val++;
            for (int col = i + p - 2; col >= i; --col)
                res[i + p - 1][col] = val++;
            for (int row = i + p - 2; row > i; --row)    
                res[row][i] = val++;
        }
        if (n % 2 != 0) res[n / 2][n / 2] = val;
        return res;
    }
};
/*
需要与第三个方法结合着看 
*/ 
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int up = 0, down = n - 1, left = 0, right = n - 1, val = 1;
        while (true) {
            for (int j = left; j <= right; ++j) res[up][j] = val++;
            if (++up > down) break;
            for (int i = up; i <= down; ++i) res[i][right] = val++;
            if (--right < left) break;
            for (int j = right; j >= left; --j) res[down][j] = val++;
            if (--down < up) break;
            for (int i = down; i >= up; --i) res[i][left] = val++;
            if (++left > right) break;
        }
        return res;
    }
};
