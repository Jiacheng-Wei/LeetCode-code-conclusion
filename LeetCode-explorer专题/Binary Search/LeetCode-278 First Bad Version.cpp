// Forward declaration of isBadVersion API.
/*这个题的思路是二分法的第二个模板，就是寻找第一个大于等于某一个值的数的位置，这个题的解题的思路可以用LeetCode上面总结的思路来解决：
 Initial Condition: left = 0, right = length
Termination: left == right
Searching Left: right = mid
Searching Right: left = mid+1
最终的返回也是返回left或right都可以，因为循环停止的条件是left==right
*/
 
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1,right=n;//注意这里的right的值一定要是n，否则在给出的最后一个测试用例时会超界 
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(isBadVersion(mid))
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        return left;
    }
};
