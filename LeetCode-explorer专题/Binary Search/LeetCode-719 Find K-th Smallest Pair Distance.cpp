/*
那么下面这种利用了桶排序的解法就是一种很好的优化，题目中给了数字的大小范围，不会超过一百万，所以我们就建立
一百万个桶，然后还是遍历任意两个数字，将计算出的距离放到对应的桶中，这里桶不是存的具体距离，而是该距离出现
的次数，桶本身的位置就是距离，所以我们才建立了一百万个桶。然后我们就可以从0开始遍历到一百万了，这样保证了我
们先处理小距离，如果某个距离的出现次数大于等于k了，那么我们返回这个距离，否则就用k减去这个距离的出现次数，
参见代码如下：
*/ 
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size(), N = 1000000;
        vector<int> cnt(N, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ++cnt[abs(nums[i] - nums[j])];
            }
        }
        for (int i = 0; i < N; ++i) {
            if (cnt[i] >= k) return i;
            k -= cnt[i];
        }
        return -1;
    }
};
/*
这道题使用的二分搜索法是博主归纳总结帖LeetCode Binary Search Summary 二分搜索法小结中的第四种，即二分法的判定
条件不是简单的大小关系，而是可以抽离出子函数的情况，下面我们来看具体怎么弄。我们的目标是快速定位出第k小的距离，
那么很适合用二分法来快速的缩小查找范围，然而最大的难点就是如何找到判定依据来折半查找，即如果确定搜索目标是在左
半边还是右半边。做过Kth Smallest Element in a Sorted Matrix和Kth Smallest Number in Multiplication Table这两道
题的同学应该对这种搜索方式并不陌生。核心思想是二分确定一个中间数，然后找到所有小于等于这个中间数的距离个数，用
其跟k比较来确定折半的方向。具体的操作是，我们首先要给数组排序，二分搜索的起始left为0，结束位置right为最大距离，
即排序后的数字最后一个元素减去首元素。然后进入while循环，算出中间值mid，此外我们还需要两个变量cnt和start，其中
cnt是记录小于等于mid的距离个数，start是较小数字的位置，均初始化为0，然后我们遍历整个数组，先进行while循环，如
果start未越界，并且当前数字减去start指向的数组之差大于mid，说明此时距离太大了，我们增加减数大小，通过将start右
移一个，那么while循环退出后，就有i - start个距离小于等于mid，将其加入cnt中，举个栗子来说：

   1    2    3    3    5

start              i

mid = 2

如果start在位置0，i在位置3，那么以nums[i]为较大数可以产生三个（i - start）小于等于mid的距离，[1 3], [2 3], [3 3]，
这样当i遍历完所有的数字后，所有小于等于mid的距离的个数就求出来了，即cnt。然后我们跟k比较，如果其小于k，那么left赋
值为mid+1，反之，则right赋值为mid。最终返回right或left均可，参见代码如下：
以上是博客上的总结，我这里简单总结下，是我对这道题的理解，一是对整个数组排序，这样相当于是对距离大小的排序；二是
确定left，right和mid值；三是，不断二分，方法是对整个数组进行遍历，计算每一对数值对的距离，然后判断其与k值的大小，然后
将其作为二分的判断条件。 
*/
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = nums.back() - nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0, start = 0;
            for (int i = 0; i < n; ++i) {
                while (start < n && nums[i] - nums[start] > mid) ++start;
                cnt += i - start;
            }
            if (cnt < k) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};
