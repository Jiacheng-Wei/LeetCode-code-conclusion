/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> pos;
        generate(sum,root,pos,res);
        return res;
    }
    void generate(int sum,TreeNode* root,vector<int>& pos,vector<vector<int> >& res)
    {
        if(!root) return;
        sum=sum-root->val;//һ��Ҫ��sum�Ĳ���д�������Ȼ������Ҷ�ӽ����ж�ʱ���ټ�ȥҶ�ӽ���ֵ 
        if(!root->left&&!root->right&&sum==0) 
        {
            pos.push_back(root->val);
            res.push_back(pos);
            pos.pop_back();
        }
        if(root->right)
        {
            pos.push_back(root->val);
            generate(sum,root->right,pos,res);
            pos.pop_back();
        }
        if(root->left)
        {
            pos.push_back(root->val);
            generate(sum,root->left,pos,res);
            pos.pop_back();
        }
    }
};
//�ܺ������Լ�������ߣ�����Ĵ��룬������м���ע�������ǰ�����ע 
