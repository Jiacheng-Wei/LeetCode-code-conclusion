/*һ���ݹ��⣬�����3sum�����������û�в����ظ�ѡ�����ֵ����ƣ�����Ҫ�ڡ�ѡindex������������֧�Ĵ����޸�Ϊ 
dfs(index,sum+candidates[index],target,pos,candidates,res);��ʾ�����ظ�ѡ��index�������ֱ��������ѡ���ֵΪֹ*/ 
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
