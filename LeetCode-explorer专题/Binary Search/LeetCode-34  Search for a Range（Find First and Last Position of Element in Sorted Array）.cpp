class Solution {
public:
    int findhead(vector<int>& nums,int target)
    {
        int left=0,right=nums.size()-1;
        while (left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]>=target)
            {
                right=mid;
            }
            else if(nums[mid]<target)
            {
                left=mid+1;
            }
        }
        return left;
    }
    
    int findtail(vector<int>& nums,int target)
    {
        int left=0,right=nums.size();//�����right����Ϊnums.size()��ԭ��������������ҿ��������ֻ���������ܱ�֤right-1��Ŀ��ֵ�����һ����Χ�������ܱ�֤������Ϊ[1],target=1�������ΪrightΪ1 
        while (left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]>target)
            {
                right=mid;
            }
            else 
            {
                left=mid+1;
            }
        }
        return right-1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.size()==0) return {-1,-1};
        int head,tail;
        head=findhead(nums,target);
        tail=findtail(nums,target);
        if(nums[head]!=target) head=tail=-1;
        res.push_back(head);
        res.push_back(tail);
        return res;
    }
};
/*
�������������һ����������������Ѱ����ͬĿ��ֵ����ʼ�ͽ���λ�ã������޶���ʱ�临�Ӷ�ΪO(logn)�����ǵ��͵Ķ��ֲ��ҷ���ʱ�临�Ӷȣ��������������Ҳ��Ҫ�ô˷��������ǵ�˼·�����ȶ�ԭ����ʹ�ö�
�ֲ��ҷ����ҳ�����һ��Ŀ��ֵ��λ�ã�Ȼ�������������ҳ���ʼ�ͽ�����λ�ã��������£�
*/ 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx = search(nums, 0, nums.size() - 1, target);
        if (idx == -1) return {-1, -1};
        int left = idx, right = idx;
        while (left > 0 && nums[left - 1] == nums[idx]) --left;
        while (right < nums.size() - 1 && nums[right + 1] == nums[idx]) ++right;
        return {left, right};
    }
    int search(vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) return search(nums, mid + 1, right, target);
        else return search(nums, left, mid - 1, target);
    }
};
/*
������Щ�˻����������㷨�����ϸ������ϵ�O(logn)���㷨����Ϊ���������»���O(n)�����統���������ȫ��Ŀ��ֵ�Ļ������м��������ұ߽�ͻ�һֱ�������������飬��ô������������һ������������
��O(logn)���㷨��ʹ�����ζ��ֲ��ҷ�����һ���ҵ���߽磬�ڶ��ε����ҵ��ұ߽缴�ɣ�����������£�
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (nums[right] != target) return res;
        res[0] = right;
        right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right= mid;
        }
        res[1] = left - 1;
        return res;
    }
};
