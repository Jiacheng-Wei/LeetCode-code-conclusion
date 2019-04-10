/*
因为regionSum要调用很多次，所以如果每次都对一个区间的值重新计算，在多次调用过后就会出现超时的情况，答案引用的方法就是
用NumMatrix函数先对每个区间的值进行一次备份，然后在regionSum函数内调用一次即可。 
*/
/*
建立一个累计区域和的数组，然后根据边界值的加减法来快速求出给定区域之和。这里我们维护一个二维数组dp，其中dp[i][j]表示累
计区间(0, 0)到(i, j)这个矩形区间所有的数字之和，那么此时如果我们想要快速求出(r1, c1)到(r2, c2)的矩形区间时，
只需dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1]即可，下面的代码中我们由于用了辅助列和辅助行，
所以下标会有些变化，参见代码如下：
这个方法是LeetCode官方给的第四个方法，就是smart caching的方法。 
*/ 
class NumMatrix {
public:
    NumMatrix(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        dp.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix[0].size(); ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
    
private:
    vector<vector<int> > dp;
};
/*
这是LeetCode上面给出的第三个方法，caching row的方法，是将二维数组转换成一维数组那样操作，将每一行作为一个整体对象。 
*/ 
class NumMatrix {
private:
    vector<vector<int> > dp;
public:
    NumMatrix(vector<vector<int>>& matrix){
        if(matrix.size()==0||matrix[0].size()==0) return;
        dp.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for(int r=0;r<matrix.size();r++){
            for(int c=0;c<matrix[0].size();c++){
                dp[r][c+1]=dp[r][c]+matrix[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int r=row1;r<=row2;r++){
            sum+=dp[r][col2+1]-dp[r][col1];
        }
        return sum;
    }
};
