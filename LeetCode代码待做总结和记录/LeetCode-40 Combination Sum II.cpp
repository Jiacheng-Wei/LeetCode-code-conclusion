class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > res;
        vector<int> pos;
        dfs(0,0,target,candidates,pos,res);
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
    void dfs(int index,int sum,int& target,vector<int>& candidates,vector<int>& pos,vector<vector<int> >& res)
    {
        if(sum==target)
        {
            res.push_back(pos);
            return;
        }
        else if(index==candidates.size()||sum>target) return;
        pos.push_back(candidates[index]);
        dfs(index+1,sum+candidates[index],target,candidates,pos,res);
        pos.pop_back();
        dfs(index+1,sum,target,candidates,pos,res);
    }
};
