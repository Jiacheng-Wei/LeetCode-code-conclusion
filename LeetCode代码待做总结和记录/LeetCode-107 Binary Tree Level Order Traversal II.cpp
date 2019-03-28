/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //���巽����ǰ��LeetCode-102�ķ���һ����ֻ�������������ʱ�����˶��� 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        dfs(root,0,res);
        return vector<vector<int> > (res.rbegin(),res.rend());//�����������˷�������������Ӻ���ǰ�������������һ����ϸ����ַ
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
//�����ķ���������queueʵ�֣���bfs�ı��Ρ���LeetCode-102����һ����ֻ�����ղ���res�ķ�ʽ������һ������ 
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
