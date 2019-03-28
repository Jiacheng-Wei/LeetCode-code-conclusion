/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //总体方法和前面LeetCode-102的方法一样，只是在最后结果返回时反向了而已 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        dfs(root,0,res);
        return vector<vector<int> > (res.rbegin(),res.rend());//这里是利用了反向迭代器，即从后向前遍历，这里给出一个详细的网址
//https://blog.csdn.net/laobai1015/article/details/51567564 
    }
    void dfs(TreeNode *root,int level,vector<vector<int> >& res)
    {
        if(!root) return;
        if(res.size()==level) res.push_back({});
        res[level].push_back(root->val);
        if(root->left) dfs(root->left,level+1,res);
        if(root->right) dfs(root->right,level+1,res);
    }
};
//迭代的方法，利用queue实现，是bfs的变形。和LeetCode-102方法一样，只是最终插入res的方式方法不一样而已 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) return res;
        queue<TreeNode*> q;
        vector<int> pos;
        q.push(root);
        while (!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *n=q.front();
                q.pop();
                pos.push_back(n->val);
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            res.insert(res.begin(),pos);
            pos.clear();
        }
        return res;
    }
}; 
