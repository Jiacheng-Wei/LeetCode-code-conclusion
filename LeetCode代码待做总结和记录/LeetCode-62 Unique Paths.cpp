/*dp���������ԭ�����֮ǰ�ǵ� Climbing Stairs �����ƣ��ǵ�����˵����ÿ������һ��������ʵ��ﶥ�������в�ͬ�����ĸ�����
���������ÿ�ο��������߻��������ߣ��󵽴������½ǵ����в�ͬ�߷��ĸ�������ô������������һ����������Ҫ�ö�̬�滮Dynamic Programming
���⣬���ǿ���ά��һ����ά����dp������dp[i][j]��ʾ����ǰλ�ò�ͬ���߷��ĸ�����Ȼ����Եõ�����ʽΪ: dp[i][j] = dp[i - 1][j] + dp[i][j - 1]��
����Ϊ�˽�ʡ�ռ䣬����ʹ��һά����dp��һ��һ�е�ˢ��Ҳ���ԣ���������: 
*/ 
//�����ܽ�һ�£�Ϊʲôi��j�ĳ�ʼֵ��Ϊ1��ԭ������Ϊ������0�л���0�е�����λ�ã������߷���ֻ��һ�֣�ʼ�����һ���ʼ������ 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1;i<m;i++)
        {
            for (int j=1;j<n;j++)
            {
                dp[j]+=dp[j-1];
            }
        }
        return dp[n-1];
    }
};
//�ݹ�Ľⷨ����������ӵĵݹ�ⷨ�������ⷨ����һ�� 
class Solution{
public:
	int uniquePaths(int m, int n) {
    	return helper(1,1,m,n);
	}
	int helper(int row, int col, int m, int n)
	{
   	 	if(row==m && col==n)
        	return 1;
    	if(row>m || col>n)
        	return 0;
    	return helper(row+1,col,m,n)+helper(row,col+1,m,n);
	}	
}; 
 /*
 ʵ���൱�ڻ������ܹ�����m + n - 2��������m - 1�������ߣ�n - 1�������ߣ���ô�ܹ���ͬ�ķ����������൱���ڲ�������m - 1��n - 1�н�
 С���Ǹ�����ȡ����ʵ������һ������������⣬д����������:
 ����Ĵ����������ϵĽ����ֻ��Ҫ��һ���л����е�ɨ�裬����ʱ�临�Ӷ���O(min(m,n))�����ռ临�Ӷ���O(1)��������������ֽⷨ���š�
 ���������и��׶ˣ�������������е�dom��dedom�������double��������int����ô�������Խ�磬��Ϊ����һ���׳ˣ����Դ��������������
 ���ַ���Ҫע����ἰԽ������⡣
 */ 
 class Solution {
public:
    int uniquePaths(int m, int n) {
        double num = 1, denom = 1;
        int small = m > n ? n : m;
        for (int i = 1; i <= small - 1; ++i) {
            num *= m + n - 1 - i;
            denom *= i;
        }
        return (int)(num / denom);
    }
};


