/*一道递归题，该题和3sum的题的区别是没有不能重复选择数字的限制，所以要在“选index号数”这条分支的代码修改为 
dfs(index,sum+candidates[index],target,pos,candidates,res);表示可以重复选择index这个数，直到不能在选这个值为止*/ 
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> pos;
        dfs(0,0,target,pos,candidates,res);
        return res;
    }
    void dfs(int index,int sum,int& target,vector<int>& pos,vector<int>& candidates,vector<vector<int> >& res)
    {
        if(sum==target)
        {
            res.push_back(pos);
            return;
        }
        if (index==candidates.size()||sum>target) return;
        pos.push_back(candidates[index]);
        dfs(index,sum+candidates[index],target,pos,candidates,res);
        pos.pop_back();
        dfs(index+1,sum,target,pos,candidates,res);
    }
};
