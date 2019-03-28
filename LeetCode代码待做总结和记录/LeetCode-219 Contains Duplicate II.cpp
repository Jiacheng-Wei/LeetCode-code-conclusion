/*
这道题是之前那道Contains Duplicate 包含重复值的延伸，不同之处在于那道题只要我们判断下数组中是否有重复值，而这道题限制了数组中只许有一组重复的数字，
而且他们坐标差不能超过k。那么我们首先需要一个哈希表，来记录每个数字和其坐标的映射，然后我们需要一个变量d来记录第一次出现重复数字的坐标差。由于题
目要求只能有一组重复的数字，所以我们在遇到重复数字时，首先判断d是否已经存了值，如果d已经有值了，说明之前有过了重复数字，则直接返回false即可。如果
没有，则此时给d附上值。在网上看到有些解法在这里就直接判断d和k的关系然后返回结果了，其实这样是不对的。因为题目要求只能有一组重复数，就是说如果后面
又出现了重复数，就没法继续判断了。所以正确的做法应该是扫描完整个数组后在判断，先看d有没有存入结果，如果没有，则说明没出现过重复数， 返回false即可。
如果d有值，再跟k比较，返回对应的结果。
*/ 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) return true;
            else m[nums[i]] = i;
        }
        return false;
    }
};
//下面是一个判断相同数位置最大差距的值
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int max=INT_MIN;
        for (int i=0;i<nums.size();i++)
        {
            if (mp.find(nums[i])==mp.end()) 
            {
                mp[nums[i]]=i;
            }
            else
            {
                if((i-mp[nums[i]])>=max)
                {
                    max=i-mp[nums[i]];
                }
            }
        }
        return max==k;
    }
}; 
