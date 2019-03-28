//dfs求解的过程要和全排列的类比，他们的不同在于 for循环中的dfs调用的起始值一定为i+1这样才能保证不重复 
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> pos;
        vector<vector<int> > res;
        dfs(n,k,1,pos,res);
        return res;
    }
    void dfs(int& n,int& k,int index,vector<int>& pos,vector<vector<int> >& res)
    {
        if (pos.size()==k) 
        {
            res.push_back(pos);
            return;
        }
        for (int i=index;i<=n;i++)
        {
            pos.push_back(i);
            dfs(n,k,i+1,pos,res);
            pos.pop_back();
        }
    }
};
/*
我们再来看一种递归的写法，此解法没用helper当递归函数，而是把本身就当作了递归函数，写起来十分的简洁，也是非常有趣的一种解法。
这个解法用到了一个重要的性质 C(n, k) = C(n-1, k-1) + C(n-1, k)，这应该在我们高中时候学排列组合的时候学过吧，博主也记不清了。
总之，翻译一下就是，在n个数中取k个数的组合项个数，等于在n-1个数中取k-1个数的组合项个数再加上在n-1个数中取k个数的组合项个数之
和。这里博主就不证明了，因为我也不会，就直接举题目中的例子来说明吧：
C(4, 2) = C(3, 1) + C(3, 2)
我们不难写出 C(3, 1) 的所有情况：[1], [2], [3]，还有 C(3, 2) 的所有情况：[1, 2], [1, 3], [2, 3]。
我们发现二者加起来为6，正好是 C(4, 2) 的个数之和。但是我们仔细看会发现，C(3, 2)的所有情况包含在 C(4, 2) 之中，
但是 C(3, 1) 的每种情况只有一个数字，而我们需要的结果k=2，其实很好办，每种情况后面都加上4，于是变成了：[1, 4], [2, 4], [3, 4]，加上C(3, 2) 
的所有情况：[1, 2], [1, 3], [2, 3]，正好就得到了 n=4, k=2 的所有情况了。参见代码如下：
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(n<0||k<0) return {};
        if(k==0) return {{}};
        vector<vector<int> > res=combine(n-1,k-1);
        for (auto &a : res) a.push_back(n);
        for (auto &a : combine(n-1,k)) res.push_back(a);
        return res;
    }
};
//迭代的方法
/*
我们再来看一种迭代的写法，也是一种比较巧妙的方法。这里每次先递增最右边的数字，存入结果res中，当右边的数字超过了n，
则增加其左边的数字，然后将当前数组赋值为左边的数字，再逐个递增，直到最左边的数字也超过了n，停止循环。对于n=4, k=2时，遍历的顺序如下所示
0 0 #initialization
1 0
1 1 
1 2 #push_back
1 3 #push_back
1 4 #push_back
1 5
2 5
2 2 
2 3 #push_back
2 4 #push_back
...
3 4 #push_back
3 5
4 5
4 4
4 5
5 5 #stop 
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out(k, 0);
        int i = 0;
        while (i >= 0) {
            ++out[i];
            if (out[i] > n) --i;
            else if (i == k - 1) res.push_back(out);
            else {
                ++i;
                out[i] = out[i - 1];
            }
        }
        return res;
    }
}; 
