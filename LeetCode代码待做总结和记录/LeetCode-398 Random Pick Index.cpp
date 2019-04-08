/*
�����ָ�������ǲ�����̫��Ŀռ䣬��ôʡ�ռ���������ֻ��ˮ������Reservoir Sampling�ˣ�LeetCode֮ǰ�й�
������Ҫ�����ַ�������ĿShuffle an Array��Linked List Random Node����ô����˽���ˮ�������������Ͳ���
һ�������ˣ����Ƕ�������������������cnt�ͷ��ؽ��res�����Ǳ����������飬��������ֵ������target��ֱ����
�����������target����������1��Ȼ��������[0,cnt)��Χ���������һ�����֣�������������0�����ǽ�res��ֵ
Ϊi���ɣ��μ��������£�
����Ҳ������ˮ������Ľ��ܣ������и������Ҿ���д��ͦ�õģ�https://www.cnblogs.com/krcys/p/9121487.html 
*/ 
class Solution {
private:
    vector<int> v;
public:
    Solution(vector<int>& nums):v(nums) {
        
    }
    
    int pick(int target) {
        int cnt=0,res=-1;
        for(int i=0;i<v.size();i++){
            if(v[i]!=target) continue;
            cnt++;
            if(rand()%cnt==0) res=i;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
