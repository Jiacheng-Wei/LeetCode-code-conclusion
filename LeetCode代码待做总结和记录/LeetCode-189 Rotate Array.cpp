class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		k%=nums.size();
		for (int i=0;i<k;i++)
        {
            vector<int>::iterator it=nums.end()-1;
            nums.insert(nums.begin(),*it);
            nums.pop_back();
        }
    }
};
/*
class Solution {
public:
    // Use reverse
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
private:
    void reverse(vector<int>& nums, int start, int end)
    {
        int left = start;
        int right = end;
        while (left < right)
        {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }
};
*/ 
// 求k的余的目的是降低执行次数，因为具有周期性，可求余以实现一次即可得出答案。方法太巧，我不知道怎么总结了，肯定有什么数学原理蕴含其中。 
// 第二种算法可能看起来难以理解，但是如果仔细分析一下的话，还是觉得很巧的一种方法，在这里解释下。 
// 第一步交换后，使数组逆序排列；第二步执行后 ，使得倒转次数以内的数逆序排列；第三部使的倒转部分以后的数恢复正常顺序。 
