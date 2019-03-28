#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT_MIN,curnum=0;
        for (int i=0;i<nums.size();i++)
        {
            curnum=max(curnum+nums[i],nums[i]);
            res=max(curnum,res);
        }
        return res;
    }
};//该算法是遍历完所有的元素的算法，所以时间复杂度为O(n)。
//贴一个网址，这里有面有详细解释：https://www.cnblogs.com/mengfanrong/p/5282042.html，就是最大值中的子串中的子串的和都不小于0。 

/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        return helper(nums, 0, (int)nums.size() - 1);
    }
    int helper(vector<int>& nums, int left, int right) {
        if (left >= right) return nums[left];
        int mid = left + (right - left) / 2;
        int lmax = helper(nums, left, mid - 1);
        int rmax = helper(nums, mid + 1, right);
        int mmax = nums[mid], t = mmax;
        for (int i = mid - 1; i >= left; --i) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        t = mmax;
        for (int i = mid + 1; i <= right; ++i) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        return max(mmax, max(lmax, rmax));
    }
};
*/ 
//该方法是一个迭代方法，就是不停的去中间值，直到获得最大值，这是在对左边和右边取最大值时的方法 
int main()
{
	vector<int> nums;
	nums.push_back(-2);
	nums.push_back(1);
	nums.push_back(-3);
	nums.push_back(4);
 	nums.push_back(-1);
 	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-5);
	nums.push_back(4);
	Solution s;
	cout<<s.maxSubArray(nums);
	return 0;
}
