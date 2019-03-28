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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int res=1;
        dfs(root,1,res);
        return res;
    }
    void dfs(TreeNode *root,int level,int &res)
    {
        if(!root->left&&!root->right)//这里一定要这么写，当其子节点为空的时候递归就应该暂停了，此处判断应该和LeetCode-102进行类比记忆 
        {
            res=max(res,level);
            return;
        }
        if(root->left) dfs(root->left,level+1,res);
        if(root->right) dfs(root->right,level+1,res);
    }
};
//自己的递归方法，我觉得还是写的挺好的 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
//另一种迭代方法，我觉得也挺好的，更简单，要理解并运用
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ++res;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *t = q.front(); q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return res;
    }
};
//迭代的方法，实际应用的是层序遍历，这里的方法和LeetCode-102的方法一致 
 
