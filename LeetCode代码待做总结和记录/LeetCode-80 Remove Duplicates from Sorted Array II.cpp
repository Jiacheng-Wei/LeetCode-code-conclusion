/*
��һ������count����¼�������м����ظ���count��ʼ��Ϊ1��������ֹ�һ���ظ�����count�ݼ�1����ô�´��ٳ����ظ�����ָ��ֱ��ǰ��һ����
�����ʱ�����ظ��ģ���count�ָ�1��������������������ģ�����һ�����ֲ��ظ���������һ����������󣬴���֮�󲻻������ظ��
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return nums.size();
        int pre=0,cur=1,count=1;
        while(cur<n)
        {
            if(nums[pre]==nums[cur]&&count==0) cur++;
            else
            {
                if(nums[pre]==nums[cur]) count--;
                else count=1;
                nums[++pre]=nums[cur++];
            }
        }
        return pre+1;
    }
};
