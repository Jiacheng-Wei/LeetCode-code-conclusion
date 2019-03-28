class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        for (int i=0;i<nums.size();i++)
        {
            if (m[nums[i]]!=NULL)
            {
                m[nums[i]]++;
            }
            else m[nums[i]]=1;
        }
        for (map<int,int>::iterator it=m.begin();it!=m.end();it++)
        {
            if (it->second==1) return it->first;
        }
    }
};
//hashmap的使用其实都不算hash表，只是调用了map这个模板 
