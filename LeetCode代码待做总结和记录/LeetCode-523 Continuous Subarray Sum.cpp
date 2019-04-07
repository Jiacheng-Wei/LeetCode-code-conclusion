/*
遇到除法问题，我们肯定不能忘了除数为0的情况等处理。还有就是我们如何能快速的遍历所有的子数组，
并且求和，我们肯定不能完全的暴力破解，这样OJ肯定不答应。我们需要适当的优化，如果是刷题老司机的话，
遇到这种求子数组或者子矩阵之和的题，应该不难想到要建立累加和数组或者累加和矩阵来做。没错，这道题
也得这么做，我们要遍历所有的子数组，然后利用累加和来快速求和。在得到每个子数组之和时，我们先和k
比较，如果相同直接返回true，否则再判断，若k不为0，且sum能整除k，同样返回true，最后遍历结束返回false，
参见代码如下：
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            int sum=nums[i];
            for(int j=i+1;j<nums.size();j++){
                sum+=nums[j];
                if(sum==k) return true;
                if(k!=0&&sum%k==0) return true;//在这个看k!=0的判断一定要放在前面才可以，否则会出现除数为0的判断 
            }
        }
        return false;
    }
};

/*
若数字a和b分别除以数字c，若得到的余数相同，那么(a-b)必定能够整除c。明白了这条定理，那么我们用一个
集合set来保存所有出现过的余数，如果当前的累加和除以k得到的余数在set中已经存在了，那么说明之前必定
有一段子数组和可以整除k。需要注意的是k为0的情况，由于无法取余，我们就把当前累加和放入set中。还有
就是题目要求子数组至少需要两个数字，那么我们需要一个变量pre来记录之前的和，我们每次存入set中的是pre，
而不是当前的累积和，参见代码如下：
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
既然set可以做，一般来说用哈希表也可以做，这里我们建立余数和当前位置之间的映射，由于有了位置信息，
我们就不需要pre变量了，之前用保存的坐标和当前位置i比较判断就可以了
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
