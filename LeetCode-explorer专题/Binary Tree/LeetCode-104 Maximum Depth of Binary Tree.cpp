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
        if(!root->left&&!root->right)//����һ��Ҫ��ôд�������ӽڵ�Ϊ�յ�ʱ��ݹ��Ӧ����ͣ�ˣ��˴��ж�Ӧ�ú�LeetCode-102������ȼ��� 
        {
            res=max(res,level);
            return;
        }
        if(root->left) dfs(root->left,level+1,res);
        if(root->right) dfs(root->right,level+1,res);
    }
};
//�Լ��ĵݹ鷽�����Ҿ��û���д��ͦ�õ� 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
//��һ�ֵ����������Ҿ���Ҳͦ�õģ����򵥣�Ҫ��Ⲣ����
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
//�����ķ�����ʵ��Ӧ�õ��ǲ������������ķ�����LeetCode-102�ķ���һ�� 
 
