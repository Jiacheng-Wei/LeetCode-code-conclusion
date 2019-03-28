class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m+n-1;
        int j=m-1;
        int k=n-1;
        
        while (i>=0)
        {
            if (j>=0&&k>=0)
            {
                if (nums1[j]>=nums2[k])
                {
                    nums1[i]=nums1[j];
                    j--;
                }
                else 
                {
                    nums1[i]=nums2[k];
                    k--;
                }
            }
            else if (j>=0)
            {
                nums1[i]=nums1[j];
                j--;
            }
            else if(k>=0)
            {
                nums1[i]=nums2[k];
                k--;
            }
            i--;
        }
    }
};
//具体这道题怎么总结才好，我也不知道，只能是多积累，这个算法的巧妙之处就是从最后一个元素入手，所以要多积累这个方法 
