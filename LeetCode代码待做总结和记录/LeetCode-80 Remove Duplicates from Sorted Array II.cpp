/*
用一个变量count来记录还允许有几次重复，count初始化为1，如果出现过一次重复，则count递减1，那么下次再出现重复，快指针直接前进一步，
如果这时候不是重复的，则count恢复1，由于整个数组是有序的，所以一旦出现不重复的数，则一定比这个数大，此数之后不会再有重复项。
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
