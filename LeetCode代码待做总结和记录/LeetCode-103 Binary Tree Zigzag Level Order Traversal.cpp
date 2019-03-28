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
//��������к���������У�����Ҫ����Ϊ������漰�����˳������s2ջ�����Ҵ棬���������ʱ�Ǵ��ҵ���� ����ôs1��Ҫ���ҵ���棬����Ǵ����ҵ� 
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
