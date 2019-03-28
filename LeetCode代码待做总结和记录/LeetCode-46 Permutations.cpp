//全排列的递归实现，需要注意的问题是第30和31行，当递归开始回回溯时一定要将mp置位true，同时要将pos中的值给pop掉 
//具体函数的实现需要的参数要根据具体的情况而定，此时但是我觉得不能缺了那个map用来判断数据是否已经被使用 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        int n=nums.size();
        vector<int> pos;
        map<int,bool> mp;
        for (int i=0;i<n;i++)
        {
            mp[nums[i]]=false;
        } 
        generate(0,n,mp,nums,pos,res);
        return res;
    }
    void generate(int index,int& n,map<int,bool>& mp,vector<int> nums,vector<int> pos,vector<vector<int> >& res)
    {
        if(index==n)
        {
            res.push_back(pos);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]==false)
            {
                pos.push_back(nums[i]);
                mp[nums[i]]=true;
                generate(index+1,n,mp,nums,pos,res);
                mp[nums[i]]=false;
                pos.pop_back();
            }
        }
    }
};
//另一种递归方式，就是不停的交换num里面的数字，然后递归完成后也能实现全排列
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        permuteDFS(num, 0, res);
        return res;
    }
    void permuteDFS(vector<int> &num, int start, vector<vector<int> > &res) {
        if (start >= num.size()) res.push_back(num);
        for (int i = start; i < num.size(); ++i) {
            swap(num[start], num[i]);
            permuteDFS(num, start + 1, res);
            swap(num[start], num[i]);
        }
    }
};
/*
最后再来看一种方法，这种方法是CareerCup书上的方法，也挺不错的，这道题是思想是这样的：
当n=1时，数组中只有一个数a1，其全排列只有一种，即为a1
当n=2时，数组中此时有a1a2，其全排列有两种，a1a2和a2a1，那么此时我们考虑和上面那种情况的关系，我们发现，其实就是在a1的前后两个位置分别加入了a2
当n=3时，数组中有a1a2a3，此时全排列有六种，分别为a1a2a3, a1a3a2, a2a1a3, a2a3a1, a3a1a2, 和 a3a2a1。那么根据上面的结论，实际上是在a1a2和a2a1
的基础上在不同的位置上加入a3而得到的。
_ a1 _ a2 _ : a3a1a2, a1a3a2, a1a2a3
_ a2 _ a1 _ : a3a2a1, a2a3a1, a2a1a3
也是递归实现的，但是有一点难以理解，因为可能思路要复杂点*/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        if (num.empty()) return vector<vector<int> >(1, vector<int>());
        vector<vector<int> > res;
        int first = num[0];
        num.erase(num.begin());
        vector<vector<int> > words = permute(num);
        for (auto &a : words) {
            for (int i = 0; i <= a.size(); ++i) {
                a.insert(a.begin() + i, first);
                res.push_back(a);
                a.erase(a.begin() + i);
            }
        }   
        return res;
    }
}; 
