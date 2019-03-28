/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*这道题主要就是考二叉树的中序遍历的非递归形式，需要额外定义一个栈来辅助，二叉搜索树的建树规则
 就是左<根<右，用中序遍历即可从小到大取出所有节点。代码如下：
 */ 
class BSTIterator {
private:
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        while(root)
        {
            s.push(root);
            root=root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* n=s.top();
        s.pop();
        int res=n->val;
        if(n->right)
        {
            n=n->right;
            while(n)
            {
                s.push(n);
                n=n->left;
            }
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(s.empty()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
