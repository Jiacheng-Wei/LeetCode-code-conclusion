class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int>::iterator it1;
        it1=nums.begin();
        vector<int>::iterator it2;
        while (it1!=nums.end())
        {
            it2=it1+1;
            while(it2!=nums.end())//翻书确定了，end()函数返回的地址是最后一个元素后一个的地址，一定记住 
            {
                if (*it1==*it2)
                {
                    nums.erase(it2);
                    //it2++;
                }
                else break;
            }
            it1++;
        }
        return nums.size();
    }
};
//注意当使用vector模板中的erase()函数时，注意一旦删除这个节点，vector向量就会改变所以不要直接就it++了，这样会出现runtime error的问题 其实就是当it已经到
//向量末尾时也，如果也刚好删除最后一个结点，此时已经是nums.end(),然后再加一，就会遇到超界的问题；同时当遇到连续的值需要删除时，也会出现漏删的情况。
//所以当调用erase(),函数后就不要直接+1。
