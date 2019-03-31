/*
���ǿ���ʹ��Trie�����ݽṹ���Ƚ����е����Զ�������ʽ�ɸߵ��ʹ���������Ӷ�����������һ��������
�ڼ������ֵʱ��ֻ����������Ϊ1�ļ��ɣ��е�̰�ĵ���˼��
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
                    cursum+=(1<<i);//���������ǽ�1����iλ��ԭ����trie���ǴӸ�λ��ʼ���´�� 
                    cur=cur->child[curbit^1];
                } 
                else cur=cur->child[curbit];
            }
            maxi=max(maxi,cursum);
        }
        return maxi;
    }
};
