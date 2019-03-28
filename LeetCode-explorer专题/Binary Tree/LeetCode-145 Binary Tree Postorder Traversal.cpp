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
    void solve(vector<int>& res,TreeNode* root)
    {
        if(root->left) solve(res,root->left);
        if(root->right) solve(res,root->right);
        if (root) res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        solve(res,root);
        return res;
    }
};
//方法一，这里应该注意多head结点的理解，可见博客https://www.cnblogs.com/grandyang/p/4251757.html 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s{{root}};
        TreeNode *head = root;
        while (!s.empty()) {
            TreeNode *t = s.top();
            if ((!t->left && !t->right) || t->left == head || t->right == head) {
                res.push_back(t->val);
                s.pop();
                head = t;
            } else {
                if (t->right) s.push(t->right);
                if (t->left) s.push(t->left);
            }
        }
        return res;
    }
};
//方法二
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s{{root}};
        while (!s.empty()) {
            TreeNode *t = s.top(); s.pop();
            res.insert(res.begin(), t->val);
            if (t->left) s.push(t->left);
            if (t->right) s.push(t->right);
        }
        return res;
    }
};
//方法三，修改自preorder方法，可以当做模板记忆，不同点是把res的push变成insert即可 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                res.insert(res.begin(), p->val);
                p = p->right;
            } else {
                TreeNode *t = s.top(); s.pop();
                p = t->left;
            }
        }
        return res;
    }
};
//方法四:双栈实现 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while (!s1.empty()) {
            TreeNode *t = s1.top(); s1.pop();
            s2.push(t);
            if (t->left) s1.push(t->left);
            if (t->right) s1.push(t->right);
        }
        while (!s2.empty()) {
            res.push_back(s2.top()->val); s2.pop();
        }
        return res;
    }
}; 
