class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int ,int> mp;
        for (int i=0;i<nums.size();i++)
        {
             if (mp[nums[i]]==NULL)
             {
                 mp[nums[i]]=1;
             }
            else mp[nums[i]]++;
        }
        int mx=INT_MIN;
        unordered_map<int,int>::iterator it_max;
        for (unordered_map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
        {
            if (mx<it->second)
            {
                it_max=it;
                mx=it->second;
            }
        }
        return it_max->first;
    }
};
//hashmap的方法，时间复杂度O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return (nums[nums.size()/2]);
    }
};
/*
sort方法：
根据题目要求，如果出现次数最大的数的数量超过 数组长度的一半时，那么排序过后，数组中间的数就是这个出现次数最大的数，此解决方案的前提是出现次数要大于n/2。
时间复杂度是O(nlgn); 
*/ 
