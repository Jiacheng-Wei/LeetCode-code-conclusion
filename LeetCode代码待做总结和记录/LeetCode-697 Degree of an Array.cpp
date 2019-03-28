#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    /*int findShortestSubArray(vector<int>& nums) {
        map<int, int> mp;
        for (int i=0;i<nums.size();i++)
        {
            if(mp.size()==0) 
            {
                mp[nums[i]]=1;
            }
            else mp[nums[i]]++;
        }
        map<int,int>::iterator it=mp.begin();
        map<int,int>::iterator it2=mp.begin();
        int mx=INT_MIN;
        for (it;it!=mp.end();it++)
        {
            mx=max(mx,it->second);
        }
        if(mx==1) return 1;
        vector<int> degree;
        for (it2;it2!=mp.end();it2++)
        {
            if(it2->second==mx) degree.push_back(it2->first);
        }
        int min=INT_MAX;
        for(int i=0;i<degree.size();i++)
        {
            vector<int>::iterator left=nums.begin();
            vector<int>::iterator right=nums.end()-1;//���˺þô����ִ������end()�������ص������һ��Ԫ�ص���һ����ַ������Ҫ��һָ���ָ�������һ��Ԫ�� 
            for (left;left!=nums.end();left++)
            {
                if (*left==degree[i]) break;
            }
            for (right;right!=nums.begin();right--)
            {
                if (*right==degree[i]) break;
            }
            if((right-left)<min)
            {
                min=(right-left);
            }
        }
        return min+1;    
    }*/
	 
};
/*
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> counter, first;//����һ��������hash������һ�����ڴ洢�״γ���Ԫ�ص��׵�ַ 
        int res = 0, degree = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (first.count(nums[i]) == 0) first[nums[i]] = i;//��¼�׵�ַ 
            if (++counter[nums[i]] > degree) {//ѡ�����Ƶ�ʳ��������� 
                degree = counter[nums[i]];
                res = i - first[nums[i]] + 1;//�����¼�׵�ַ�ķ����ܺã������õ�ǰ����Ԫ�ص�index-�׵�ַ���Ϳ��Լ�¼���Ƶ�ʵ����ķ�Χ 
            } else if (counter[nums[i]] == degree)//�ò����жϵ�����������Ƶ����ͬ�����ǣ�Ѱ����С��Χ�Ĵ�С 
                res = min(res, i - first[nums[i]] + 1);
        }
        return res;
    }
*/
//����ķ����Ƚ��ƣ������˼·�ǣ��������е�ע�� 

int main()
{
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(5);
	nums.push_back(5);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(6);
	nums.push_back(6);
	Solution s;
	cout<<s.findShortestSubArray(nums);
	return 0;
 } 
