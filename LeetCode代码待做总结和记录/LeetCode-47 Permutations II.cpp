/*
还有一种比较简便的方法，在Permutations的基础上稍加修改，我们用set来保存结果，利用其不会有重复项的特点，然后我们再递归函数中的swap的地方，
判断如果i和start不相同，但是nums[i]和nums[start]相同的情况下跳过，继续下一个循环，参见代码如下： 
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        permute(nums, 0, res);
        return vector<vector<int>> (res.begin(), res.end());
    }
    void permute(vector<int> &nums, int start, set<vector<int>> &res) {
        if (start >= nums.size()) res.insert(nums);
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            permute(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
};
/*
这道题是之前那道 Permutations 全排列的延伸，由于输入数组有可能出现重复数字，如果按照之前的算法运算，会有重复排列产生，我们要避免重复的产生，
在递归函数中要判断前面一个数和当前的数是否相等，如果相等，前面的数必须已经使用了，即对应的visited中的值为1，当前的数字才能使用，否则需要跳
过，这样就不会产生重复排列了，代码如下：
*/ 
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> visit(nums.size(),0);
        vector<int> pos;
        sort(nums.begin(),nums.end());
        dfs(0,nums,visit,pos,res);
        return res;
    }
    void dfs(int index,vector<int>& nums,vector<int>& visit,vector<int>& pos,vector<vector<int> >& res)
    {
        if(index==nums.size()) 
        {
            res.push_back(pos);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(visit[i]==0)
            {
                if(i>0&&nums[i]==nums[i-1]&&visit[i-1]==0) continue;
                pos.push_back(nums[i]);
                visit[i]=1;
                dfs(index+1,nums,visit,pos,res);
                pos.pop_back();
                visit[i]=0;
            }
        }
    }
};
