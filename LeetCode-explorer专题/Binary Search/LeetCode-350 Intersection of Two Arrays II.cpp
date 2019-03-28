/*
�������Intersection of Two Arrays���ַ������ϵ�һ���Ľ���������⵽nums2�еĹ���Ԫ��֮���ɾ����nums2�еĹ���Ԫ�أ�Ȼ�����²��ҡ�
������Ҳ��ϰ��vectorģ���е�erase��remove���÷���erase�������ɾ��Ԫ�أ��ǻ��ڵ�����ʹ�õģ�����remove������������ɾ��һ��ֵ�����ǰ�
���ֵ�����������ط�����������λ��https://blog.csdn.net/zzuchengming/article/details/50895535 
*/ 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums2.begin(),nums2.end());
        for(auto a:nums1)
        {
            if(binarySearch(nums2,a))
            {
                res.push_back(a);
            }
        }
        return res;
    }
    bool binarySearch(vector<int>& nums, int target)
    {
        if(nums.empty()) return false;
        int left=0,right=nums.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                nums.erase(nums.begin()+mid);
                return true;
            }
            else if(nums[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return false;
    }
};
/*
������һ�ַ��������ַ����ȸ�������������Ȼ��������ָ��ֱ�ָ�������������ʼλ�ã�
�������ָ��ָ��������ȣ���������У�����ָ�������1�������һ��ָ��ָ�����ִ�
��ڶ���ָ������1����֮��Ȼ���μ��������£� 
*/ 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i; ++j;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                ++i;
            }
        }
        return res;
    }
};
/*
�������֮ǰ�ǵ�Intersection of Two Arrays����չ����֮ͬ������������������Ƿ����ظ�������
�������Ǿ����ܶ�ķ��أ�֮ǰ�ǵ�����˵���ظ�������ֻ����һ�����С���ô����������ù�ϣ����
����nums1���ַ�������ָ���֮���ӳ��, Ȼ�����nums2���飬�����ǰ�ַ��ڹ�ϣ���еĸ�������0
���򽫴��ַ�������res�У�Ȼ���ϣ��Ķ�Ӧֵ�Լ�1���μ��������£�
*/ 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> res;
        for (auto a : nums1) ++m[a];
        for (auto a : nums2) {
            if (m[a]-- > 0) res.push_back(a);
        }
        return res;
    }
};
