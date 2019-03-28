class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it;
        it=nums.begin();
        while(it!=nums.end())
        {
            if(val==*it)
            {
                nums.erase(it);
                continue;
            }
            it++;
        }
        return nums.size();
    }
};
//注意当使用vector模板中的erase()函数时，注意一旦删除这个节点，vector向量就会改变所以不要直接就it++了，这样会出现runtime error的问题 其实就是当it已经到
//向量末尾时也，如果也刚好删除最后一个结点，此时已经是nums.end(),然后再加一，就会遇到超界的问题；同时当遇到连续的值需要删除时，也会出现漏删的情况。
//所以当调用erase(),函数后就不要直接+1。
