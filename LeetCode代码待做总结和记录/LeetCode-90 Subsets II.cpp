//递归解决这个问题，和subset的这道题的不同点是在dfs的最后一步中有一个去重的步骤，如果遇到重复的元素就跳过，防止出现重复的项 
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> pos;
        sort(nums.begin(),nums.end());
        dfs(0,nums,pos,res);
        return res;
    }
    void dfs(int index,vector<int>& nums,vector<int>& pos,vector<vector<int> >& res )
    {
        res.push_back(pos);
        for (int i=index;i<nums.size();i++)
        {
            pos.push_back(nums[i]);
            dfs(i+1,nums,pos,res);
            pos.pop_back();
            while(i+1<nums.size()&&nums[i]==nums[i+1]) i++;
        }
    }
};
//用迭代的方法解决这个问题
/*
这道子集合之二是之前那道 Subsets 子集合 的延伸，这次输入数组允许有重复项，其他条件都不变，只需要在之前那道题解法的基础上
稍加改动便可以做出来，我们先来看非递归解法，拿题目中的例子[1 2 2]来分析，根据之前 Subsets 子集合 里的分析可知，当处理到
第一个2时，此时的子集合为[], [1], [2], [1, 2]，而这时再处理第二个2时，如果在[]和[1]后直接加2会产生重复，所以只能在上一个
循环生成的后两个子集合后面加2，发现了这一点，题目就可以做了，我们用last来记录上一个处理的数字，然后判定当前的数字和上面的
是否相同，若不同，则循环还是从0到当前子集的个数，若相同，则新子集个数减去之前循环时子集的个数当做起点来循环，这样就不会产
生重复了，代码如下：
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<vector<int> > res(1);
        sort(nums.begin(),nums.end());
        int size=1,last=nums[0];
        for (int i=0;i<nums.size();i++)
        {
            if(last!=nums[i])
            {
                last=nums[i];
                size=res.size();
            }
            int newsize=res.size();
            for (int j=newsize-size;j<newsize;j++)
            {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
}; 
