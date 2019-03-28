class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int mx=INT_MIN;
        if (nums.size()==0) return 0;
        if (nums.size()==1) return 1;
        for (int i=0;i<nums.size()-1;i++)
        {
            int j=1;
            for (int k=i;k<nums.size()-1;k++)
            {
                if (nums[k]<nums[k+1])
                {
                    j++;
                }
                else 
                {
                    i=i+j-1;//注意这个不能是i+=k。 
                    break;
                }
            }
            mx=max(j,mx);
        }
        return mx;
    }
};
//注意循环的终点是nums.size()。 
