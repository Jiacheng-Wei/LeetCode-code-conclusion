/*
我们可以使用Trie树数据结构，先将所有的数以二进制形式由高到低存放起来，从而方便我们下一步遍历。
在计算异或值时，只添加两者异或为1的即可，有点贪心的意思。
*/
class TrieNode{
public:
    TrieNode* child[2];
    TrieNode(){
        child[0]=NULL;
        child[1]=NULL;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        if(nums.empty()) return NULL;
        TrieNode* root=new TrieNode();
        for(auto num:nums)
        {
            TrieNode* cur=root;
            for(int i=31;i>=0;i--)
            {
                int curbit=(num>>i)&1;
                if(!cur->child[curbit]){
                    cur->child[curbit]=new TrieNode();
                    cur=cur->child[curbit];
                } 
                else cur=cur->child[curbit];
            }
        }
        int maxi=INT_MIN;
        for(auto num:nums)
        {
            TrieNode* cur=root;
            int cursum=0;
            for(int i=31;i>=0;i--)
            {
                int curbit=(num>>i)&1;
                if(cur->child[curbit^1]){
                    cursum+=(1<<i);//这里的理解是将1右移i位，原因是trie树是从高位开始向下存的 
                    cur=cur->child[curbit^1];
                } 
                else cur=cur->child[curbit];
            }
            maxi=max(maxi,cursum);
        }
        return maxi;
    }
};
