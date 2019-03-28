class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int i=0;i<nums.size();i++)
        {
            if (st.find(nums[i])!=st.end()) return true;
            else 
            {
                st.insert(st.end(),nums[i]);
            }
        }
        return false;
    }
};
//使用了set模板，然后就是还可以使用hash表或者利用排序找到连在一起的相同值 
