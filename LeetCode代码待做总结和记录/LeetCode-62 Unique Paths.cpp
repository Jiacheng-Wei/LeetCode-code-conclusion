/*dp解决方法，原来这跟之前那道 Climbing Stairs 很类似，那道题是说可以每次能爬一格或两格，问到达顶部的所有不同爬法的个数。
而这道题是每次可以向下走或者向右走，求到达最右下角的所有不同走法的个数。那么跟爬梯子问题一样，我们需要用动态规划Dynamic Programming
来解，我们可以维护一个二维数组dp，其中dp[i][j]表示到当前位置不同的走法的个数，然后可以得到递推式为: dp[i][j] = dp[i - 1][j] + dp[i][j - 1]，
这里为了节省空间，我们使用一维数组dp，一行一行的刷新也可以，代码如下: 
*/ 
//这里总结一下，为什么i和j的初始值都为1，原因是以为无论是0行还是0列的所有位置，他的走法都只有一种，始终向右或者始终向下 
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
//递归的解法，类比爬梯子的递归解法，两个解法几乎一致 
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
 实际相当于机器人总共走了m + n - 2步，其中m - 1步向下走，n - 1步向右走，那么总共不同的方法个数就相当于在步数里面m - 1和n - 1中较
 小的那个数的取法，实际上是一道组合数的问题，写出代码如下:
 下面的代码求解了组合的结果，只需要做一次行或者列的扫描，所以时间复杂度是O(min(m,n))，而空间复杂度是O(1)。比起上面的两种解法更优。
 不过这里有个弊端，就是如果代码中的dom和dedom如果不是double，而是用int，那么会很容易越界，因为这是一个阶乘，所以大家在面试中讨论
 这种方法要注意和提及越界的问题。
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


