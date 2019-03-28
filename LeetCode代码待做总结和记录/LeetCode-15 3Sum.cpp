//理解递归思路，但是会time limit exceed 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> >res;
        vector<int> pos;
        Dfs(0,0,0,pos,nums,res);
        sort(res.begin(),res.end());//下面两步是为了删除重复元素 
        res.erase(unique(res.begin(),res.end()),res.end());//unique函数的作用是将相邻的相同的元素移动到数组最后面 
        return res;
    }
    void Dfs(int index,int time,int sum,vector<int>& pos,vector<int>& nums,vector<vector<int> >& res)
    {
        if (time==3&&sum==0)
        {
            res.push_back(pos);
            return;
        }
        if(index==nums.size()||time>3||sum>0) return;
        pos.push_back(nums[index]);
        Dfs(index+1,time+1,sum+nums[index],pos,nums,res);
        pos.pop_back();
        Dfs(index+1,time,sum,pos,nums,res);
    }
};
//用类2sum解决问题
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
        for (int k = 0; k < nums.size(); ++k) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int target = 0 - nums[k];
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                } else if (nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return res;
    }
};
/*
我们对原数组进行排序，然后开始遍历排序后的数组，这里注意不是遍历到最后一个停止，而是到倒数第三个就可以了。这里我们可以先做个剪
枝优化，就是当遍历到正数的时候就break，为啥呢，因为我们的数组现在是有序的了，如果第一个要fix的数就是正数了，那么后面的数字就都
是正数，就永远不会出现和为0的情况了。然后我们还要加上重复就跳过的处理，处理方法是从第二个数开始，如果和前面的数字相等，就跳过，
因为我们不想把相同的数字fix两次。对于遍历到的数，用0减去这个fix的数得到一个target，然后只需要再之后找到两个数之和等于target即
可。我们用两个指针分别指向fix数字之后开始的数组首尾两个数，如果两个数和正好为target，则将这两个数和fix的数一起存入结果中。然后
就是跳过重复数字的步骤了，两个指针都需要检测重复数字。如果两数之和小于target，则我们将左边那个指针i右移一位，使得指向的数字增大
一些。同理，如果两数之和大于target，则我们将右边那个指针j左移一位，使得指向的数字减小一些，
*/ 
