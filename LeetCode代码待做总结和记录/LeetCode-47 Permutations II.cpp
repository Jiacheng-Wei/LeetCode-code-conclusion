/*
����һ�ֱȽϼ��ķ�������Permutations�Ļ������Լ��޸ģ�������set���������������䲻�����ظ�����ص㣬Ȼ�������ٵݹ麯���е�swap�ĵط���
�ж����i��start����ͬ������nums[i]��nums[start]��ͬ�������������������һ��ѭ�����μ��������£� 
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
�������֮ǰ�ǵ� Permutations ȫ���е����죬�������������п��ܳ����ظ����֣��������֮ǰ���㷨���㣬�����ظ����в���������Ҫ�����ظ��Ĳ�����
�ڵݹ麯����Ҫ�ж�ǰ��һ�����͵�ǰ�����Ƿ���ȣ������ȣ�ǰ����������Ѿ�ʹ���ˣ�����Ӧ��visited�е�ֵΪ1����ǰ�����ֲ���ʹ�ã�������Ҫ��
���������Ͳ�������ظ������ˣ��������£�
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
