/*
�������֮ǰ�ǵ�Contains Duplicate �����ظ�ֵ�����죬��֮ͬ�������ǵ���ֻҪ�����ж����������Ƿ����ظ�ֵ���������������������ֻ����һ���ظ������֣�
�������������ܳ���k����ô����������Ҫһ����ϣ������¼ÿ�����ֺ��������ӳ�䣬Ȼ��������Ҫһ������d����¼��һ�γ����ظ����ֵ�����������
ĿҪ��ֻ����һ���ظ������֣����������������ظ�����ʱ�������ж�d�Ƿ��Ѿ�����ֵ�����d�Ѿ���ֵ�ˣ�˵��֮ǰ�й����ظ����֣���ֱ�ӷ���false���ɡ����
û�У����ʱ��d����ֵ�������Ͽ�����Щ�ⷨ�������ֱ���ж�d��k�Ĺ�ϵȻ�󷵻ؽ���ˣ���ʵ�����ǲ��Եġ���Ϊ��ĿҪ��ֻ����һ���ظ���������˵�������
�ֳ������ظ�������û�������ж��ˡ�������ȷ������Ӧ����ɨ����������������жϣ��ȿ�d��û�д����������û�У���˵��û���ֹ��ظ����� ����false���ɡ�
���d��ֵ���ٸ�k�Ƚϣ����ض�Ӧ�Ľ����
*/ 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) return true;
            else m[nums[i]] = i;
        }
        return false;
    }
};
//������һ���ж���ͬ��λ��������ֵ
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int max=INT_MIN;
        for (int i=0;i<nums.size();i++)
        {
            if (mp.find(nums[i])==mp.end()) 
            {
                mp[nums[i]]=i;
            }
            else
            {
                if((i-mp[nums[i]])>=max)
                {
                    max=i-mp[nums[i]];
                }
            }
        }
        return max==k;
    }
}; 
