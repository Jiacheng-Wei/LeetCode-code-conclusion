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
};//���㷨�Ǳ��������е�Ԫ�ص��㷨������ʱ�临�Ӷ�ΪO(n)��
//��һ����ַ��������������ϸ���ͣ�https://www.cnblogs.com/mengfanrong/p/5282042.html���������ֵ�е��Ӵ��е��Ӵ��ĺͶ���С��0�� 

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
//�÷�����һ���������������ǲ�ͣ��ȥ�м�ֵ��ֱ��������ֵ�������ڶ���ߺ��ұ�ȡ���ֵʱ�ķ��� 
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
