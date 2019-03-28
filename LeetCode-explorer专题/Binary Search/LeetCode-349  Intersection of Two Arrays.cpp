/*
这道题让我们找两个数组交集的部分（不包含重复数字），难度不算大，我们可以用个set把nums1都放进去，
然后遍历nums2的元素，如果在set中存在，说明是交集的部分，加入结果的set中，最后再把结果转为vector
的形式即可：
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(),nums1.end()),res;
        for(auto a : nums2)
        {
            if(s.count(a)) res.insert(a);
        }
        return vector<int>(res.begin(),res.end()); 
    }
};
/*
我们还可以使用两个指针来做，先给两个数组排序，然后用两个指针分别指向两个数组的开头，然后比较两个
数组的大小，把小的数字的指针向后移，如果两个指针指的数字相等，那么看结果res是否为空，如果为空或者
是最后一个数字和当前数字不等的话，将该数字加入结果res中，参见代码如下：
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i=0,j=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]<nums2[j]) i++;
            else if(nums2[j]<nums1[i]) j++;
            else 
            {
                if(res.empty()||res.back()!=nums1[i])
                {
                    res.push_back(nums1[i]);
                }
                i++,j++;
            }
        }
        return res;
    }
};
/*
我们还可以使用二分查找法来做，思路是将一个数组排序，然后遍历另一个数组，把遍历到的每个数字在排序号
的数组中用二分查找法搜索，如果能找到则放入结果set中，这里我们用到了set的去重复的特性，最后我们将set
转为vector即可：
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
        sort(nums2.begin(),nums2.end());
        for(auto a:nums1){
            if(binarySearch(nums2,a))
               {
                   res.insert(a);
               }
        }
        return vector<int>(res.begin(),res.end());
    }
    bool binarySearch(vector<int>& nums,int target){
        int left=0,right=nums.size();
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]>target) right=mid;
            else  left=mid+1;
        }
        return false;
    }
};
//注意二分查找的边界问题，做类似题的时候记得考虑特殊情况，只有一个或两个值的数组这种情况
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
        sort(nums2.begin(),nums2.end());
        for(auto a:nums1){
            if(binarySearch(nums2,a))
               {
                   res.insert(a);
               }
        }
        return vector<int>(res.begin(),res.end());
    }
    bool binarySearch(vector<int>& nums,int target){
        int left=0,right=nums.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]>target) right=mid-1;
            else  left=mid+1;
        }
        return false;
    }
}; 
/*或者我们也可以使用STL的set_intersection函数来找出共同元素，很方便：*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), res;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
        return vector<int>(res.begin(), res.end());
    }
};
