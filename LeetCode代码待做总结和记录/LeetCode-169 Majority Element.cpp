class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int ,int> mp;
        for (int i=0;i<nums.size();i++)
        {
             if (mp[nums[i]]==NULL)
             {
                 mp[nums[i]]=1;
             }
            else mp[nums[i]]++;
        }
        int mx=INT_MIN;
        unordered_map<int,int>::iterator it_max;
        for (unordered_map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
        {
            if (mx<it->second)
            {
                it_max=it;
                mx=it->second;
            }
        }
        return it_max->first;
    }
};
//hashmap�ķ�����ʱ�临�Ӷ�O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return (nums[nums.size()/2]);
    }
};
/*
sort������
������ĿҪ��������ִ������������������� ���鳤�ȵ�һ��ʱ����ô������������м��������������ִ������������˽��������ǰ���ǳ��ִ���Ҫ����n/2��
ʱ�临�Ӷ���O(nlgn); 
*/ 
