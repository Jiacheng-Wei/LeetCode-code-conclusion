class Solution {
public:
    int findhead(vector<int>& nums,int target)
    {
        int left=0,right=nums.size()-1;
        while (left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]>=target)
            {
                right=mid;
            }
            else if(nums[mid]<target)
            {
                left=mid+1;
            }
        }
        return left;
    }
    
    int findtail(vector<int>& nums,int target)
    {
        int left=0,right=nums.size();//这里把right设置为nums.size()的原因是类似于左闭右开的情况，只有这样才能保证right-1是目标值的最后一个范围，而且能保证在输入为[1],target=1的情况下为right为1 
        while (left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]>target)
            {
                right=mid;
            }
            else 
            {
                left=mid+1;
            }
        }
        return right-1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.size()==0) return {-1,-1};
        int head,tail;
        head=findhead(nums,target);
        tail=findtail(nums,target);
        if(nums[head]!=target) head=tail=-1;
        res.push_back(head);
        res.push_back(tail);
        return res;
    }
};
/*
这道题让我们在一个有序整数数组中寻找相同目标值的起始和结束位置，而且限定了时间复杂度为O(logn)，这是典型的二分查找法的时间复杂度，所以这道题我们也需要用此方法，我们的思路是首先对原数组使用二
分查找法，找出其中一个目标值的位置，然后向两边搜索找出起始和结束的位置，代码如下：
*/ 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx = search(nums, 0, nums.size() - 1, target);
        if (idx == -1) return {-1, -1};
        int left = idx, right = idx;
        while (left > 0 && nums[left - 1] == nums[idx]) --left;
        while (right < nums.size() - 1 && nums[right + 1] == nums[idx]) ++right;
        return {left, right};
    }
    int search(vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) return search(nums, mid + 1, right, target);
        else return search(nums, left, mid - 1, target);
    }
};
/*
可能有些人会觉得上面的算法不是严格意义上的O(logn)的算法，因为在最坏的情况下会变成O(n)，比如当数组里的数全是目标值的话，从中间向两边找边界就会一直遍历完整个数组，那么我们下面来看一种真正意义上
的O(logn)的算法，使用两次二分查找法，第一次找到左边界，第二次调用找到右边界即可，具体代码如下：
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (nums[right] != target) return res;
        res[0] = right;
        right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right= mid;
        }
        res[1] = left - 1;
        return res;
    }
};
