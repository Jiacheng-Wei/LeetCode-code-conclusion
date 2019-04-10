/*
��ΪregionSumҪ���úܶ�Σ��������ÿ�ζ���һ�������ֵ���¼��㣬�ڶ�ε��ù���ͻ���ֳ�ʱ������������õķ�������
��NumMatrix�����ȶ�ÿ�������ֵ����һ�α��ݣ�Ȼ����regionSum�����ڵ���һ�μ��ɡ� 
*/
/*
����һ���ۼ�����͵����飬Ȼ����ݱ߽�ֵ�ļӼ��������������������֮�͡���������ά��һ����ά����dp������dp[i][j]��ʾ��
������(0, 0)��(i, j)��������������е�����֮�ͣ���ô��ʱ���������Ҫ�������(r1, c1)��(r2, c2)�ľ�������ʱ��
ֻ��dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1]���ɣ�����Ĵ����������������˸����к͸����У�
�����±����Щ�仯���μ��������£�
���������LeetCode�ٷ����ĵ��ĸ�����������smart caching�ķ����� 
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
����LeetCode��������ĵ�����������caching row�ķ������ǽ���ά����ת����һά����������������ÿһ����Ϊһ��������� 
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
