/*
可以理解为爬山，而且求的是局部最大值，所以只要满足一个情况就可以了 
于题目中提示了要用对数级的时间复杂度，那么我们就要考虑使用类似于二分查找法来缩短时间，由于只是需要找到任意一个峰值，
那么我们在确定二分查找折半后中间那个元素后，和紧跟的那个元素比较下大小，如果大于，则说明峰值在前面，如果小于则在后
面。这样就可以找到一个峰值了，代码如下：
*/ 
class Solution {
public:
    int findPeakElement(vector<int>& nums){
         int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]<nums[mid+1]) left=mid+1;
            else right=mid;
        }
        return left;//这里return left或right都是一样的 
    }
};
/*
我们可以对上面的线性扫描的方法进行一些优化，可以省去首尾垫值的步骤。由于题目中说明了局部峰值一定存在，那么实际上可以从
第二个数字开始往后遍历，如果第二个数字比第一个数字小，说明此时第一个数字就是一个局部峰值；否则就往后继续遍历，现在是个
递增趋势，如果此时某个数字小于前面那个数字，说明前面数字就是一个局部峰值，返回位置即可。如果循环结束了，说明原数组是个
递增数组，返回最后一个位置即可，参见代码如下：
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) return i - 1;
        }
        return nums.size() - 1;
    }
};
/*
这道题是求数组的一个峰值，如果这里用遍历整个数组找最大值肯定会出现Time Limit Exceeded，但题目中说了这个峰值可以是局部的
最大值，所以我们只需要找到第一个局部峰值就可以了。所谓峰值就是比周围两个数字都大的数字，那么只需要跟周围两个数字比较就可
以了。既然要跟左右的数字比较，就得考虑越界的问题，题目中给了nums[-1] = nums[n] = -∞，那么我们其实可以把这两个整型最小值
直接加入到数组中，然后从第二个数字遍历到倒数第二个数字，这样就不会存在越界的可能了。由于题目中说了峰值一定存在，那么有一
个很重要的corner case我们要注意，就是当原数组中只有一个数字，且是整型最小值的时候，我们如果还要首尾垫数字，就会形成一条水
平线，从而没有峰值了，所以我们对于数组中只有一个数字的情况在开头直接判断一下即可，参见代码如下：
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MIN);
        for (int i = 1; i < (int)nums.size() - 1; ++i) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i - 1;
        }
        return -1;
    }
};

