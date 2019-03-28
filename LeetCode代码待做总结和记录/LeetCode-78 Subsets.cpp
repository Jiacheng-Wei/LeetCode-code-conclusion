/*首先要知道的一个确定的步骤是，当遇到这种排列问题是，一定要先将数组等进行排序，然后再进行接下来的步骤，原因是，排序过后能够更好地判断
是否存在重复的元素并能够更好的对已经使用的元素进行标记*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res(1);
        sort(nums.begin(),nums.end()); 
        int S_size=nums.size();
        for (int i=0;i<S_size;i++)
        {
            int size=res.size();
            for(int j=0;j<size;j++)
            {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);//这里调用back()函数一定不要少了括号 
            }
        }
        return res;
    }
};
/*
这道题其实它的非递归解法相对来说更简单一点，下面我们先来看非递归的解法，由于题目要求子集合中数字的顺序是非降序排列的，
所有我们需要预处理，先给输入数组排序，然后再进一步处理，最开始我在想的时候，是想按照子集的长度由少到多全部写出来，比
如子集长度为0的就是空集，空集是任何集合的子集，满足条件，直接加入。下面长度为1的子集，直接一个循环加入所有数字，子集
长度为2的话可以用两个循环，但是这种想法到后面就行不通了，因为循环的个数不能无限的增长，所以我们必须换一种思路。我们可
以一位一位的网上叠加，比如对于题目中给的例子[1,2,3]来说，最开始是空集，那么我们现在要处理1，就在空集上加1，为[1]，现
在我们有两个自己[]和[1]，下面我们来处理2，我们在之前的子集基础上，每个都加个2，可以分别得到[2]，[1, 2]，那么现在所有
的子集合为[], [1], [2], [1, 2]，同理处理3的情况可得[3], [1, 3], [2, 3], [1, 2, 3], 再加上之前的子集就是所有的子集合了，
代码如上： 
*/
//递归的方法做这道题，在subset的里面因为不出现重复的元素所以还比较好做一点，但是出现了重复的元素就需要考虑其他的问题了，先给出该题的递归解法 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> pos;
        sort(nums.begin(),nums.end());
        dfs(0,nums,pos,res);
        return res;
    }
    void dfs(int index,vector<int>& nums,vector<int>& pos,vector<vector<int> >& res)//这里的res一定是要引用，因为引用是在原来的内存上操作，否则res是新创建的内存 
    {
        res.push_back(pos);//注意这里和全排列dfs的不同 
        for(int i=index;i<nums.size();i++)
        {
            pos.push_back(nums[i]);
            dfs(i+1,nums,pos,res);
            pos.pop_back();
        }
    }
};
