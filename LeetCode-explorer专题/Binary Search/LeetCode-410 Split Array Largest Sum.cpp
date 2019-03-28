/*
我们首先来分析，如果m和数组nums的个数相等，那么每个数组都是一个子数组，所以返回nums中最大的数字即可，
如果m为1，那么整个nums数组就是一个子数组，返回nums所有数字之和，所以对于其他有效的m值，返回的值必定
在上面两个值之间，所以我们可以用二分搜索法来做。我们用一个例子来分析，nums = [1, 2, 3, 4, 5], m = 3，
我们将left设为数组中的最大值5，right设为数字之和15，然后我们算出中间数为10，我们接下来要做的是找出和
最大且小于等于10的子数组的个数，[1, 2, 3, 4], [5]，可以看到我们无法分为3组，说明mid偏大，所以我们让
right=mid，然后我们再次进行二分查找哦啊，算出mid=7，再次找出和最大且小于等于7的子数组的个数，[1,2,3], [4], [5]，
我们成功的找出了三组，说明mid还可以进一步降低，我们让right=mid，然后我们再次进行二分查找哦啊，算出mid=6，再次找
出和最大且小于等于6的子数组的个数，[1,2,3], [4], [5]，我们成功的找出了三组，我们尝试着继续降低mid，我们让right=mid，
然后我们再次进行二分查找哦啊，算出mid=5，再次找出和最大且小于等于5的子数组的个数，[1,2], [3], [4], [5]，发现有4组，
此时我们的mid太小了，应该增大mid，我们让left=mid+1，此时left=6，right=5，循环退出了，我们返回left即可，参见代码如下：
*/ 
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long left=0,right=0;
        for (int i=0;i<nums.size();i++)
        {
            left=max((int)left,nums[i]);
            right+=nums[i];
        }
        while(left<right)
        {
            long mid=left+(right-left)/2;
            if(can_splite(nums,m,mid)) right=mid;
            else left=mid+1;
        }
        return left;
    }
    bool can_splite(vector<int> nums, int m, int sum)
    {
        int cnt=1;
        long cntSum=0;
        for(int i=0;i<nums.size();i++)
        {
            cntSum+=nums[i];
            if(cntSum>sum)
            {
                cntSum=nums[i];
                cnt++;
                if(cnt>m) return false;
            }
        }
        return true;
    }
};
/*
我们建立一个二维数组dp，其中dp[i][j]表示将数组中前j个数字分成i组所能得到的最小的各个子数组中最大值，
初始化为整型最大值，如果无法分为i组，那么还是保持为整型最大值。为了能快速的算出子数组之和，我们还
是要建立累计和数组，难点就是在于要求递推公式了。我们来分析，如果前j个数字要分成i组，那么i的范围是
什么，由于只有j个数字，如果每个数字都是单独的一组，那么最多有j组；如果将整个数组看为一个整体，那
么最少有1组，所以i的范围是[1, j]，所以我们要遍历这中间所有的情况，假如中间任意一个位置k，dp[i-1][k]表示
数组中前k个数字分成i-1组所能得到的最小的各个子数组中最大值，而sums[j]-sums[k]就是后面的数字之和，我们取
二者之间的较大值，然后和dp[i][j]原有值进行对比，更新dp[i][j]为二者之中的较小值，这样k在[1, j]的范围内扫
过一遍，dp[i][j]就能更新到最小值，我们最终返回dp[m][n]即可，博主认为这道题所用的思想应该是之前那道题Reverse Pairs
中解法二中总结的分割重现关系(Partition Recurrence Relation)，由此看来很多问题的本质都是一样，但是披上华丽的外衣，
难免会让人有些眼花缭乱了，参见代码如下：
*/ 
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = i - 1; k < j; ++k) {
                    int val = max(dp[i - 1][k], sums[j] - sums[k]);
                    dp[i][j] = min(dp[i][j], val);
                }
            }
        }
        return dp[m][n];
    }
};
