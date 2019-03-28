#include <stdio.h>
#include <vector>
//#include <>
using namespace std;

    int searchInsert(vector<int>& nums, int target) {
        vector<int>::iterator left;
        vector<int>::iterator right;
        vector<int>::iterator mid;
        left=nums.begin();
        right=nums.end();
        while(left<right)
        {
            mid=left+(right-left)/2;//为了防止left+right太大超界所以用这种方法 
            //if(target==*mid) return mid-nums.begin();
            else if(target>*mid)
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        return left-nums.begin();
    }   
    //需要仔细总结二分法的精髓，分三种情况，这种情况属于如何找到第一个大于等于target的值的位置。 
