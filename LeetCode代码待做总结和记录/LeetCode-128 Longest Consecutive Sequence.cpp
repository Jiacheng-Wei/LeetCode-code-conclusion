//�������ٽ���������е��жϣ�ʱ�临�Ӷ�ΪO(nlgn)����������ĿҪ���Ӷ�ΪO(n)��Ҫ�� 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=1,num=1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=nums[i+1])
            {
                if(nums[i+1]==nums[i]+1)
                {
                    num++;
                }
                else
                {
                    res=max(res,num);
                    num=1;
                }
            }
        }
        return max(num,res);
    }
}; 
/*
������O(n)���Ӷ����ƣ����ǵ�˼·�ǣ�ʹ��һ������set�������е����֣�Ȼ����������е�ÿ�����֣�������ڼ����д��ڣ�
��ô�����Ƴ���Ȼ��ֱ�����������pre��next�����ǰһ��������һ������Ȼ���ڼ�����ѭ�����ң����pre�ڼ����У���ô��
pre�Ƴ����ϣ�Ȼ��pre���Լ�1��ֱ��pre���ڼ���֮�У���next����ͬ���ķ�������ônext-pre-1���ǵ�ǰ���ֵ���������У�
����res���ɡ�
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int val : nums) {
            if (!s.count(val)) continue;
            s.erase(val);
            int pre = val - 1, next = val + 1;
            while (s.count(pre)) s.erase(pre--);
            while (s.count(next)) s.erase(next++);
            res = max(res, next - pre - 1);
        }
        return res;
    }
};
/*
����Ҳ���Բ��ù�ϣ���������տ�ʼ��ϣ��Ϊ�գ�Ȼ������������֣���������ֲ��ڹ�ϣ���У���ô���Ƿֱ����������������Ƿ��ڹ�
ϣ���У�����ڣ��򷵻����ϣ����ӳ��ֵ�������ڣ��򷵻�0��Ȼ�����ǽ�left+right+1��Ϊ��ǰ���ֵ�ӳ�䣬������res�����Ȼ�����
d-left��d-right��ӳ��ֵ���μ��������£�
*/ 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int d : nums) {
            if (!m.count(d)) {
                int left = m.count(d - 1) ? m[d - 1] : 0;
                int right = m.count(d + 1) ? m[d + 1] : 0;
                int sum = left + right + 1;
                m[d] = sum;
                res = max(res, sum);
                m[d - left] = sum;
                m[d + right] = sum;
            }
        }
        return res;
    }
};
