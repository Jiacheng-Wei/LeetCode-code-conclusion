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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) return res;
        queue<TreeNode* > node;
        node.push(root);
        while (!node.empty())
        {
            vector<int> elevel;
            int size=node.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* n=node.front();
                node.pop();
                elevel.push_back(n->val);
                if(n->left) node.push(n->left);
                if(n->right) node.push(n->right);
            }
            res.push_back(elevel);
        }
        return res;
    }
};
//����ķ�����bfs�ķ��������������bfs������ԭʼ���֣����������˶�ÿ��ı�ǣ���һ�����õ�forѭ�������
// Recursive
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        levelorder(root, 0, res);
        return res;
    }
    void levelorder(TreeNode *root, int level, vector<vector<int> > &res) {
        if (!root) return;
//������������£�����һ�����ж�ֻ���ж���ʼ�Ƿ�Ϊ�գ���Ϊ���ݺ�����жϣ�Ҫ
//������һ�������ж�Ϊ�շ����Ը���������Ϊ�յ�������������������������в�Ӱ�� ���ú�104��Ƚ� 
        if (res.size() == level) res.push_back({});//��һ�����������±�����ʱ��һֱ�ᴴ��������û�л��ݣ�ֻ����һ����֧��ȥ�ˣ�ÿһ��Ҳ�ʹ������� 
        res[level].push_back(root->val);
        if (root->left) levelorder(root->left, level + 1, res);
        if (root->right) levelorder(root->right, level + 1, res);
    }
}; 
