class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> minu=triangle[triangle.size()-1];
        for(int i=triangle.size()-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                minu[j]=(minu[j]<minu[j+1]?minu[j]:minu[j+1])+triangle[i][j];
            }
        }
        return minu[0];
    }
};
/*
动态规划问题，很经典，差不多能理解了，但是还需要多加练习，探索更巧的方法。 
这个题的方法很巧妙，相比于从上至下的遍历方式，从下至上的遍历方式更简单，也更能够满足题目对空间复杂度O(n)的限制，先声明一个数组的
长度为最后一排数组的长度，然后可以上下相邻的若转化成二维数组一一对应的情况，实际上就是上面的数组就是和minu[j]和minu[j+1]相邻，然后
我们只需要更新minu数组即可，只有这样是满足空间复杂度为O(n)的情况，代码具体见上： 
*/
