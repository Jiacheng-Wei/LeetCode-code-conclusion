/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //这道题我用了一个数组存储每一个路径的值，每一个路径的值通过递归求出答案，在要回溯的时候一定要去掉改节点的印记，只用除一下10就好了 
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
