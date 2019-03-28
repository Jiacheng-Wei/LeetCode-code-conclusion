/*
当数组中存在大量的重复数字时，就会破坏二分查找法的机制，我们无法取得O(lgn)的时间复杂度，又将会回到简单粗暴的O(n)，
比如如下两种情况：
{2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 2} 和 {2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2}， 我们发现，当第一个数字和最后一个数字，
还有中间那个数字全部相等的时候，二分查找法就崩溃了，因为它无法判断到底该去左半边还是右半边。这种情况下，我们将右指针
左移一位，略过一个相同数字，这对结果不会产生影响，因为我们只是去掉了一个相同的，然后对剩余的部分继续用二分查找法，在
最坏的情况下，比如数组所有元素都相同，时间复杂度会升到O(n)，参见代码如下:
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]<nums[right]) right=mid;
            else if(nums[mid]==nums[right]) right--;
            else left=mid+1;
        }
        return nums[left];
    }
};
