//Brute Force：真暴力算法，LeetCode上面跑了1512ms也是创下了记录了 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int Max=INT_MIN;
        int n=height.size();
        for(int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                int pro=(j-i)*min(height[i],height[j]);
                Max=max(Max,pro);
            }
        }
        return Max;
    }
};
//two pointer的方法 ：定义两个指针，两个指针都向中间移动，然后由于要找最大的面积，所以保留最大的那一边，矮的那一边向中间移动。详细可以见solution
/*
The intuition behind this approach is that the area formed between the lines will always be limited by the height of the shorter line. 
Further, the farther the lines, the more will be the area obtained. We take two pointers, one at the beginning and one at the end of 
the array constituting the length of the lines. Futher, we maintain a variable maxareamaxarea to store the maximum area obtained till 
now. At every step, we find out the area formed between them, update maxareamaxarea and move the pointer pointing to the shorter line 
towards the other end by one step. The algorithm can be better understood by looking at the example below:

How this approach works?

Initially we consider the area constituting the exterior most lines. Now, to maximize the area, we need to consider the area between 
the lines of larger lengths. If we try to move the pointer at the longer line inwards, we won't gain any increase in area, since it 
is limited by the shorter line. But moving the shorter line's pointer could turn out to be beneficial, as per the same argument, despite 
the reduction in the width. This is done since a relatively longer line obtained by moving the shorter line's pointer might overcome 
the reduction in area caused by the width reduction.
*/ 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int Max=INT_MIN;
        int n=height.size();
        int l=0,r=n-1;
        while (l<r)
        {
            int pro=(r-l)*min(height[r],height[l]);
            Max=max(Max,pro);
            if(height[r]>height[l])
                l++;
            else r--;
        }
        return Max;
    }
};
