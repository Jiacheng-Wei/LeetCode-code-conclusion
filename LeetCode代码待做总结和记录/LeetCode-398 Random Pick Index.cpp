/*
这道题指明了我们不能用太多的空间，那么省空间的随机方法只有水塘抽样Reservoir Sampling了，LeetCode之前有过
两道需要用这种方法的题目Shuffle an Array和Linked List Random Node。那么如果了解了水塘抽样，这道题就不算
一道难题了，我们定义两个变量，计数器cnt和返回结果res，我们遍历整个数组，如果数组的值不等于target，直接跳
过；如果等于target，计数器加1，然后我们在[0,cnt)范围内随机生成一个数字，如果这个数字是0，我们将res赋值
为i即可，参见代码如下：
这里也补充下水塘问题的介绍，这里有个博客我觉得写得挺好的：https://www.cnblogs.com/krcys/p/9121487.html 
*/ 
class Solution {
private:
    vector<int> v;
public:
    Solution(vector<int>& nums):v(nums) {
        
    }
    
    int pick(int target) {
        int cnt=0,res=-1;
        for(int i=0;i<v.size();i++){
            if(v[i]!=target) continue;
            cnt++;
            if(rand()%cnt==0) res=i;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
