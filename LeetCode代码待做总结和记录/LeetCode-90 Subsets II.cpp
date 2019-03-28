//�ݹ���������⣬��subset�������Ĳ�ͬ������dfs�����һ������һ��ȥ�صĲ��裬��������ظ���Ԫ�ؾ���������ֹ�����ظ����� 
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
//�õ����ķ�������������
/*
����Ӽ���֮����֮ǰ�ǵ� Subsets �Ӽ��� �����죬������������������ظ���������������䣬ֻ��Ҫ��֮ǰ�ǵ���ⷨ�Ļ�����
�ԼӸĶ�������������������������ǵݹ�ⷨ������Ŀ�е�����[1 2 2]������������֮ǰ Subsets �Ӽ��� ��ķ�����֪��������
��һ��2ʱ����ʱ���Ӽ���Ϊ[], [1], [2], [1, 2]������ʱ�ٴ���ڶ���2ʱ�������[]��[1]��ֱ�Ӽ�2������ظ�������ֻ������һ��
ѭ�����ɵĺ������Ӽ��Ϻ����2����������һ�㣬��Ŀ�Ϳ������ˣ�������last����¼��һ����������֣�Ȼ���ж���ǰ�����ֺ������
�Ƿ���ͬ������ͬ����ѭ�����Ǵ�0����ǰ�Ӽ��ĸ���������ͬ�������Ӽ�������ȥ֮ǰѭ��ʱ�Ӽ��ĸ������������ѭ���������Ͳ����
���ظ��ˣ��������£�
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
