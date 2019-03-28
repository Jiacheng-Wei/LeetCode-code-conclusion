/*
���������������������������ֵ������ܴ���k��ֵ��ܴ���t������������brute force�ᳬʱ��
��������ֻ������辶����������ʹ��map���ݽṹ����,������¼���ֺ����±�֮���ӳ�䣬map��ʵ�־���BSTʵ�ֵģ�
����mapҲ���Զ��������Ҳ��Ϊʲô������lower_bound��ԭ�� ������Ҫ����ָ��i��j���տ�ʼi��j��ָ��0��Ȼ��i��ʼ
�����߱������飬���i��j֮�����k����m����nums[j]����ɾ��jȻ��j�ټ�һ��������֤��m�����е������±�֮�������k��
Ȼ��������map���ݽṹ��lower_bound()��������һ���ض���Χ�����Ǵ��ڻ����nums[i] - t�ĵط�������С�������ֵ����
��nums[i]�Ĳ�ľ���ֵ�����t (�����д�������)��Ȼ�����������е����֣�������Ĳ�ľ���ֵС�ڵ���t���򷵻�true��
���������������鷵��false���������£�
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long,int> m;
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i-j>k) m.erase(nums[j++]);
            auto a=m.lower_bound((long long)nums[i] - t);
            if(a!=m.end()&&abs(a->first-nums[i])<=t) return true;
            m[nums[i]]=i;
        }
        return false;
    }
};
