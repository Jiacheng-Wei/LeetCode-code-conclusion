/*
����Ҫ�ж�������������Ƿ���ת�ˣ�ͨ���Ƚϵ�һ�������һ�����Ĵ�С�������һ����С����û����ת��ֱ�ӷ���������������һ������
��Ҫ��һ�����������Ƕ���left��right����ָ��ֱ�ָ��ͷ�ͽ�β����Ҫ�ҵ��м��Ǹ�����Ȼ���leftָ�����Ƚϣ�����м�����������
���ֲ����Ұ�����飬��֮�������Ρ���ֹ�����ǵ���������ָ�����ڣ�����С���Ǹ����������£�
*/ 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        if(nums[left]>nums[right])
        {
            while(left!=(right-1))
            {
                int mid=left+(right-left)/2;
                if(nums[left]<nums[mid]) left=mid;
                else right=mid;
            }
            return min(nums[left],nums[right]);
        }
        return nums[0];
    }
};
