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
            vector<int>::iterator right=nums.end()-1;//找了好久错，发现错在这里，end()函数返回的是最后一个元素的下一个地址，所以要减一指针才指的是最后一个元素 
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
        unordered_map<int, int> counter, first;//定义一个计数的hash表，定义一个用于存储首次出现元素的首地址 
        int res = 0, degree = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (first.count(nums[i]) == 0) first[nums[i]] = i;//记录首地址 
            if (++counter[nums[i]] > degree) {//选择出现频率出现最大的数 
                degree = counter[nums[i]];
                res = i - first[nums[i]] + 1;//这里记录首地址的方法很好，就是用当前检查的元素的index-首地址，就可以记录最大频率的数的范围 
            } else if (counter[nums[i]] == degree)//该步是判断当有两个出现频率相同的数是，寻找最小范围的大小 
                res = min(res, i - first[nums[i]] + 1);
        }
        return res;
    }
*/
//这个的方法比较绕，具体的思路是，见代码中的注释 

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
