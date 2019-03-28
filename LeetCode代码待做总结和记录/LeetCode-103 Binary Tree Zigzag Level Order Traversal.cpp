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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        vector<int> pos;
        if (!root) return res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while (!s1.empty()||!s2.empty())
        {
            while (!s1.empty())
            {
                TreeNode *n=s1.top();
                s1.pop();
                pos.push_back(n->val);
                if(n->left) s2.push(n->left);
                if(n->right) s2.push(n->right);
//这里的两行和下面的两行，很重要，因为这个题涉及到输出顺序，所以s2栈从左到右存，但是在输出时是从右到左的 ，那么s1就要从右到左存，输出是从左到右的 
            }
            if(!pos.empty()) res.push_back(pos);
            pos.clear();
            while(!s2.empty())
            {
                TreeNode *n=s2.top();
                s2.pop();
                pos.push_back(n->val);
                if(n->right) s1.push(n->right);
                if(n->left) s1.push(n->left);
            }
            if(!pos.empty()) res.push_back(pos);
            pos.clear();
        }
        return res;
    }
};
