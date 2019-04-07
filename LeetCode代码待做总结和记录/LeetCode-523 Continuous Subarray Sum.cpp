/*
�����������⣬���ǿ϶��������˳���Ϊ0������ȴ������о�����������ܿ��ٵı������е������飬
������ͣ����ǿ϶�������ȫ�ı����ƽ⣬����OJ�϶�����Ӧ��������Ҫ�ʵ����Ż��������ˢ����˾���Ļ���
��������������������Ӿ���֮�͵��⣬Ӧ�ò����뵽Ҫ�����ۼӺ���������ۼӺ;���������û�������
Ҳ����ô��������Ҫ�������е������飬Ȼ�������ۼӺ���������͡��ڵõ�ÿ��������֮��ʱ�������Ⱥ�k
�Ƚϣ������ֱͬ�ӷ���true���������жϣ���k��Ϊ0����sum������k��ͬ������true����������������false��
�μ��������£�
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            int sum=nums[i];
            for(int j=i+1;j<nums.size();j++){
                sum+=nums[j];
                if(sum==k) return true;
                if(k!=0&&sum%k==0) return true;//�������k!=0���ж�һ��Ҫ����ǰ��ſ��ԣ��������ֳ���Ϊ0���ж� 
            }
        }
        return false;
    }
};

/*
������a��b�ֱ��������c�����õ���������ͬ����ô(a-b)�ض��ܹ�����c������������������ô������һ��
����set���������г��ֹ��������������ǰ���ۼӺͳ���k�õ���������set���Ѿ������ˣ���ô˵��֮ǰ�ض�
��һ��������Ϳ�������k����Ҫע�����kΪ0������������޷�ȡ�࣬���ǾͰѵ�ǰ�ۼӺͷ���set�С�����
������ĿҪ��������������Ҫ�������֣���ô������Ҫһ������pre����¼֮ǰ�ĺͣ�����ÿ�δ���set�е���pre��
�����ǵ�ǰ���ۻ��ͣ��μ��������£�
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0,pre=0;
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int t=(k==0)? sum:sum%k;
            if(st.count(t)) return true;
            st.insert(pre);
            pre=t;
        }
        return false;
    }
}; 
/*
��Ȼset��������һ����˵�ù�ϣ��Ҳ���������������ǽ��������͵�ǰλ��֮���ӳ�䣬��������λ����Ϣ��
���ǾͲ���Ҫpre�����ˣ�֮ǰ�ñ��������͵�ǰλ��i�Ƚ��жϾͿ�����
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        unordered_map<int, int> m{{0,-1}};
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int t = (k == 0) ? sum : (sum % k);
            if (m.count(t)) {
                if (i - m[t] > 1) return true;
            } else m[t] = i;
        }
        return false;
    }
};
