//���ݹ�˼·�����ǻ�time limit exceed 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> >res;
        vector<int> pos;
        Dfs(0,0,0,pos,nums,res);
        sort(res.begin(),res.end());//����������Ϊ��ɾ���ظ�Ԫ�� 
        res.erase(unique(res.begin(),res.end()),res.end());//unique�����������ǽ����ڵ���ͬ��Ԫ���ƶ������������ 
        return res;
    }
    void Dfs(int index,int time,int sum,vector<int>& pos,vector<int>& nums,vector<vector<int> >& res)
    {
        if (time==3&&sum==0)
        {
            res.push_back(pos);
            return;
        }
        if(index==nums.size()||time>3||sum>0) return;
        pos.push_back(nums[index]);
        Dfs(index+1,time+1,sum+nums[index],pos,nums,res);
        pos.pop_back();
        Dfs(index+1,time,sum,pos,nums,res);
    }
};
//����2sum�������
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
        for (int k = 0; k < nums.size(); ++k) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int target = 0 - nums[k];
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                } else if (nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return res;
    }
};
/*
���Ƕ�ԭ�����������Ȼ��ʼ�������������飬����ע�ⲻ�Ǳ��������һ��ֹͣ�����ǵ������������Ϳ����ˡ��������ǿ�����������
֦�Ż������ǵ�������������ʱ���break��Ϊɶ�أ���Ϊ���ǵ�����������������ˣ������һ��Ҫfix�������������ˣ���ô��������־Ͷ�
������������Զ������ֺ�Ϊ0������ˡ�Ȼ�����ǻ�Ҫ�����ظ��������Ĵ����������Ǵӵڶ�������ʼ�������ǰ���������ȣ���������
��Ϊ���ǲ������ͬ������fix���Ρ����ڱ�������������0��ȥ���fix�����õ�һ��target��Ȼ��ֻ��Ҫ��֮���ҵ�������֮�͵���target��
�ɡ�����������ָ��ֱ�ָ��fix����֮��ʼ��������β�����������������������Ϊtarget��������������fix����һ��������С�Ȼ��
���������ظ����ֵĲ����ˣ�����ָ�붼��Ҫ����ظ����֡��������֮��С��target�������ǽ�����Ǹ�ָ��i����һλ��ʹ��ָ�����������
һЩ��ͬ���������֮�ʹ���target�������ǽ��ұ��Ǹ�ָ��j����һλ��ʹ��ָ������ּ�СһЩ��
*/ 
