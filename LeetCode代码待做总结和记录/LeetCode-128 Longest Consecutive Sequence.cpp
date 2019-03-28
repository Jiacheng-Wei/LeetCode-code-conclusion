//先排序再进行最长子序列的判断，时间复杂度为O(nlgn)，不满足题目要求复杂度为O(n)的要求 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=1,num=1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=nums[i+1])
            {
                if(nums[i+1]==nums[i]+1)
                {
                    num++;
                }
                else
                {
                    res=max(res,num);
                    num=1;
                }
            }
        }
        return max(num,res);
    }
}; 
/*
给定了O(n)复杂度限制，我们的思路是，使用一个集合set存入所有的数字，然后遍历数组中的每个数字，如果其在集合中存在，
那么将其移除，然后分别用两个变量pre和next算出其前一个数跟后一个数，然后在集合中循环查找，如果pre在集合中，那么将
pre移除集合，然后pre再自减1，直至pre不在集合之中，对next采用同样的方法，那么next-pre-1就是当前数字的最长连续序列，
更新res即可。
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int val : nums) {
            if (!s.count(val)) continue;
            s.erase(val);
            int pre = val - 1, next = val + 1;
            while (s.count(pre)) s.erase(pre--);
            while (s.count(next)) s.erase(next++);
            res = max(res, next - pre - 1);
        }
        return res;
    }
};
/*
我们也可以采用哈希表来做，刚开始哈希表为空，然后遍历所有数字，如果该数字不在哈希表中，那么我们分别看其左右两个数字是否在哈
希表中，如果在，则返回其哈希表中映射值，若不在，则返回0，然后我们将left+right+1作为当前数字的映射，并更新res结果，然后更新
d-left和d-right的映射值，参见代码如下：
*/ 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int d : nums) {
            if (!m.count(d)) {
                int left = m.count(d - 1) ? m[d - 1] : 0;
                int right = m.count(d + 1) ? m[d + 1] : 0;
                int sum = left + right + 1;
                m[d] = sum;
                res = max(res, sum);
                m[d - left] = sum;
                m[d + right] = sum;
            }
        }
        return res;
    }
};
