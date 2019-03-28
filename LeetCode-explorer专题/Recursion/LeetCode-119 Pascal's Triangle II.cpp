/*
参考博客:https://www.cnblogs.com/grandyang/p/4031536.html 
杨辉三角形第n层（顶层称第0层，第1行，第n层即第n+1行，此处n为包含0在内的自然数）正好对应于二项式\left(a+b\right)^{n}展开的系数。
例如第二层1 2 1是幂指数为2的二项式\left(a+b\right)^{2}展开形式a^{2}+2ab+b^{2}的系数。
杨辉三角主要有下列五条性质：
杨辉三角以正整数构成，数字左右对称，每行由1开始逐渐变大，然后变小，回到1。
第n行的数字个数为n个。
第n行的第k个数字为组合数C_{n-1}^{k-1}。
第n行数字和为2^{n-1}。
除每行最左侧与最右侧的数字以外，每个数字等于它的左上方与右上方两个数字之和（也就是说，第n行第k个数字等于第n-1行的第k-1个数字与第k个数字的和）。
这是因为有组合恒等式：C_{n}^{i}=C_{n-1}^{i-1}+C_{n-1}^{i}。可用此性质写出整个杨辉三角形。
 

由于题目有额外限制条件，程序只能使用O(k)的额外空间，那么这样就不能把每行都算出来，而是要用其他的方法, 我最先考虑用的是第三条性质，
算出每个组合数来生成第n行系数本地调试输出前十行，没啥问题，拿到OJ上测试，程序在第18行跪了，中间有个系数不正确。那么问题出在哪了呢，
仔细找找，原来出在计算组合数那里，由于算组合数时需要算连乘，而整形数int的数值范围只有-32768到32768之间，那么一旦n值过大，连乘肯定
无法计算。而丧心病狂的OJ肯定会测试到成百上千行，所以这个方法不行。
*/ 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> out;
        if (rowIndex < 0) return out;
        for (int i = 0; i <= rowIndex; ++i) {
            if ( i == 0 || i == rowIndex) out.push_back(1);
            else out.push_back (computeCnk(rowIndex, i));
        }
        return out;
    }
     
    int computeCnk(int n, int k) {
        if (k > n) return 0;
        if (k > n/2) k = n - k;
        int numerator = 1, denominator = 1;
        for (int i = 0; i < k; ++i) {
            numerator *= n - i;
            denominator *= k - i;
        }
        if (denominator != 0) return numerator/denominator;
        return 0;
    }
};
/*
那么我们再来考虑利用第五条性质，除了第一个和最后一个数字之外，其他的数字都是上一行左右两个值之和。那么我们只需要两个for循环，
除了第一个数为1之外，后面的数都是上一次循环的数值加上它前面位置的数值之和，不停地更新每一个位置的值，便可以得到第n行的数字，
具体实现代码如下：
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j >= 1; --j) {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};
//自己的方法，和上面的思想是一样的，空间复杂度满足要求，但是时间复杂度超了，所以oj过不了
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if(rowIndex<0) return res;
        for(int i=0;i<=rowIndex;i++)
        {
            res.push_back(recur(rowIndex,i));
        }
        return res;
        
    }
    int recur(int row, int column)
    {
        if(row<0||column>row) return 0;
        else if(column==row||column==0) return 1;
        else return recur(row-1,column)+recur(row-1,column-1);
    }
}; 

