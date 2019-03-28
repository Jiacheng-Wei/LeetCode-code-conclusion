/*
这道题给我们了一个数组，还有两个变量k和x。让我们找数组中离x最近的k个元素，而且说明了数组是有序的，如果两个数字距离x相等的话，取较小的那个。
从给定的例子可以分析出x不一定是数组中的数字，我们想，由于数组是有序的，所以最后返回的k个元素也一定是有序的，那么其实就是返回了原数组的一个
长度为k的子数组，转化一下，实际上相当于在长度为n的数组中去掉n-k个数字，而且去掉的顺序肯定是从两头开始去，因为距离x最远的数字肯定在首尾出现。
那么问题就变的明朗了，我们每次比较首尾两个数字跟x的距离，将距离大的那个数字删除，直到剩余的数组长度为k为止，参见代码如下：
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res = arr;
        while (res.size() > k) {
            int first  = 0, last = res.size() - 1;
            if (x - res.front() <= res.back() - x) {
                res.pop_back();
            } else {
                res.erase(res.begin());
            }
        }
        return res;
    }
};
/*
下面这种解法是论坛上的高分解法，用到了二分搜索法。其实博主最开始用的方法并不是帖子中的这两个方法，虽然也是用的二分搜索法，但博主搜的是第一个
不小于x的数，然后同时向左右两个方向遍历，每次取和x距离最小的数加入结果res中，直到取满k个为止。但是下面这种方法更加巧妙一些，二分法的判定条件
做了一些改变，就可以直接找到要返回的k的数字的子数组的起始位置，感觉非常的神奇。每次比较的是mid位置和x的距离跟mid+k跟x的距离，以这两者的大小关
系来确定二分法折半的方向，最后找到最近距离子数组的起始位置，参见代码如下：
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
            else right = mid;
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
