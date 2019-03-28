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
//上面的方法是bfs的方法，不过相对于bfs方法的原始部分，这里增加了对每层的标记，用一个内置的for循环解决。
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
//大脑里边跑了下，发现一步的判断只能判断起始是否为空，因为根据后面的判断，要
//进行下一步首先判断为空否，所以根本不会有为空的情况，但是这种情况在这个题中不影响 ，该和104题比较 
        if (res.size() == level) res.push_back({});//这一个条件在向下遍历的时候一直会创建，好像没有回溯，只有有一个分支下去了，每一层也就创建完了 
        res[level].push_back(root->val);
        if (root->left) levelorder(root->left, level + 1, res);
        if (root->right) levelorder(root->right, level + 1, res);
    }
}; 
