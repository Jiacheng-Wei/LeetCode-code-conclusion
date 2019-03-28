/*
首先要判断这个有序数组是否旋转了，通过比较第一个和最后一个数的大小，如果第一个数小，则没有旋转，直接返回这个数。如果第一个数大，
就要进一步搜索。我们定义left和right两个指针分别指向开头和结尾，还要找到中间那个数，然后和left指的数比较，如果中间的数大，则继续
二分查找右半段数组，反之查找左半段。终止条件是当左右两个指针相邻，返回小的那个。代码如下：
*/ 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        if(nums[left]>nums[right])
        {
            while(left!=(right-1))
            {
                int mid=left+(right-left)/2;
                if(nums[left]<nums[mid]) left=mid;
                else right=mid;
            }
            return min(nums[left],nums[right]);
        }
        return nums[0];
    }
};
