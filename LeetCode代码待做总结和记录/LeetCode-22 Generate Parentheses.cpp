/*一种递归方式，应该是dfs的方式，岔路口应该是选择'('还是选择')'，然后为了降低时间复杂度，需要剪枝，就是要有open<n和close<open的判断，
因为只有在右括号数小于已有左括号数的时候才成立*/ 
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0,0,n,res,"");
        return res;
    }
    void dfs(int open,int close,int n,vector<string>& res,string r)
    {
        if(r.length()==2*n)
        {
            res.push_back(r);
            return;
        }
        if(open<n)
        {
            dfs(open+1,close,n,res,r+'(');
        }
        if (close<open)
        {
            dfs(open,close+1,n,res,r+')');
        }
    }
};
//这里给一个巧方法，但是考试的时候可能一时想不到，所以熟练掌握上面的方法很重要
/*
再来看那一种方法，这种方法是CareerCup书上给的方法，感觉也是满巧妙的一种方法，这种方法的思想是找左括号，每找到一个左括号，就在其后
面加一个完整的括号，最后再在开头加一个()，就形成了所有的情况，需要注意的是，有时候会出现重复的情况，所以我们用set数据结构，好处是
如果遇到重复项，不会加入到结果中，最后我们再把set转为vector即可，参见代码如下:
n＝1:    ()

n=2:    (())    ()()

n=3:    (()())    ((()))    ()(())    (())()    ()()() 
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> t;
        if (n == 0) t.insert("");
        else {
            vector<string> pre = generateParenthesis(n - 1);
            for (auto a : pre) {
                for (int i = 0; i < a.size(); ++i) {
                    if (a[i] == '(') {
                        a.insert(a.begin() + i + 1, '(');
                        a.insert(a.begin() + i + 2, ')');
                        t.insert(a);
                        a.erase(a.begin() + i + 1, a.begin() + i + 3);
                    }
                }
                t.insert("()" + a);
            }
        }
        return vector<string>(t.begin(), t.end());
    }
}; 
