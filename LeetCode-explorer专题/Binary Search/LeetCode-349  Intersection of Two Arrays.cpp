/*
��������������������齻���Ĳ��֣��������ظ����֣����ѶȲ�������ǿ����ø�set��nums1���Ž�ȥ��
Ȼ�����nums2��Ԫ�أ������set�д��ڣ�˵���ǽ����Ĳ��֣���������set�У�����ٰѽ��תΪvector
����ʽ���ɣ�
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(),nums1.end()),res;
        for(auto a : nums2)
        {
            if(s.count(a)) res.insert(a);
        }
        return vector<int>(res.begin(),res.end()); 
    }
};
/*
���ǻ�����ʹ������ָ���������ȸ�������������Ȼ��������ָ��ֱ�ָ����������Ŀ�ͷ��Ȼ��Ƚ�����
����Ĵ�С����С�����ֵ�ָ������ƣ��������ָ��ָ��������ȣ���ô�����res�Ƿ�Ϊ�գ����Ϊ�ջ���
�����һ�����ֺ͵�ǰ���ֲ��ȵĻ����������ּ�����res�У��μ��������£�
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i=0,j=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]<nums2[j]) i++;
            else if(nums2[j]<nums1[i]) j++;
            else 
            {
                if(res.empty()||res.back()!=nums1[i])
                {
                    res.push_back(nums1[i]);
                }
                i++,j++;
            }
        }
        return res;
    }
};
/*
���ǻ�����ʹ�ö��ֲ��ҷ�������˼·�ǽ�һ����������Ȼ�������һ�����飬�ѱ�������ÿ�������������
���������ö��ֲ��ҷ�������������ҵ��������set�У����������õ���set��ȥ�ظ������ԣ�������ǽ�set
תΪvector���ɣ�
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
        sort(nums2.begin(),nums2.end());
        for(auto a:nums1){
            if(binarySearch(nums2,a))
               {
                   res.insert(a);
               }
        }
        return vector<int>(res.begin(),res.end());
    }
    bool binarySearch(vector<int>& nums,int target){
        int left=0,right=nums.size();
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]>target) right=mid;
            else  left=mid+1;
        }
        return false;
    }
};
//ע����ֲ��ҵı߽����⣬���������ʱ��ǵÿ������������ֻ��һ��������ֵ�������������
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
        sort(nums2.begin(),nums2.end());
        for(auto a:nums1){
            if(binarySearch(nums2,a))
               {
                   res.insert(a);
               }
        }
        return vector<int>(res.begin(),res.end());
    }
    bool binarySearch(vector<int>& nums,int target){
        int left=0,right=nums.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]>target) right=mid-1;
            else  left=mid+1;
        }
        return false;
    }
}; 
/*��������Ҳ����ʹ��STL��set_intersection�������ҳ���ͬԪ�أ��ܷ��㣺*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), res;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
        return vector<int>(res.begin(), res.end());
    }
};
