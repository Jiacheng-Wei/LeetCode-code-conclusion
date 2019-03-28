// Forward declaration of isBadVersion API.
/*������˼·�Ƕ��ַ��ĵڶ���ģ�壬����Ѱ�ҵ�һ�����ڵ���ĳһ��ֵ������λ�ã������Ľ����˼·������LeetCode�����ܽ��˼·�������
 Initial Condition: left = 0, right = length
Termination: left == right
Searching Left: right = mid
Searching Right: left = mid+1
���յķ���Ҳ�Ƿ���left��right�����ԣ���Ϊѭ��ֹͣ��������left==right
*/
 
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1,right=n;//ע�������right��ֵһ��Ҫ��n�������ڸ��������һ����������ʱ�ᳬ�� 
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
