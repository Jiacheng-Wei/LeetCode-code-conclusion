/*
这里有两个限制条件，两个数字的坐标差不能大于k，值差不能大于t。这道题如果用brute force会超时，
所以我们只能另辟蹊径。这里我们使用map数据结构来解,用来记录数字和其下标之间的映射，map的实现就是BST实现的，
所以map也是自动排了序的也是为什么可以用lower_bound的原因。 这里需要两个指针i和j，刚开始i和j都指向0，然后i开始
向右走遍历数组，如果i和j之差大于k，且m中有nums[j]，则删除j然后j再加一。这样保证了m中所有的数的下标之差都不大于k，
然后我们用map数据结构的lower_bound()函数来找一个特定范围，就是大于或等于nums[i] - t的地方，所有小于这个阈值的数
和nums[i]的差的绝对值会大于t (可自行带数检验)。然后检测后面的所有的数字，如果数的差的绝对值小于等于t，则返回true。
最后遍历完整个数组返回false。代码如下：
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long,int> m;
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i-j>k) m.erase(nums[j++]);
            auto a=m.lower_bound((long long)nums[i] - t);
            if(a!=m.end()&&abs(a->first-nums[i])<=t) return true;
            m[nums[i]]=i;
        }
        return false;
    }
};
