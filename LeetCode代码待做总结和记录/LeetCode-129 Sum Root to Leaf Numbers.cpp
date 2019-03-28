/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //�����������һ������洢ÿһ��·����ֵ��ÿһ��·����ֵͨ���ݹ�����𰸣���Ҫ���ݵ�ʱ��һ��Ҫȥ���Ľڵ��ӡ�ǣ�ֻ�ó�һ��10�ͺ��� 
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector<int> res;
        int sum=0,num=0;
        dfs(root,num,res);
        for(int i=0;i<res.size();i++)
        {
            sum=sum+res[i];
        }
        return sum;
    }
    void dfs(TreeNode* root,int& num,vector<int>& res)
    {
        if (!root) return;
        num=num*10+root->val;
        if(!root->left&&!root->right) 
        {
            res.push_back(num);
        }
        if(root->left) 
        {
            dfs(root->left,num,res);
            num=num/10;
        }
        if(root->right)
        {
            dfs(root->right,num,res);
            num=num/10;
        }
    }
};
