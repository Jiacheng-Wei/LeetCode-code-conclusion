/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*�������Ҫ���ǿ�����������������ķǵݹ���ʽ����Ҫ���ⶨ��һ��ջ�������������������Ľ�������
 ������<��<�ң�������������ɴ�С����ȡ�����нڵ㡣�������£�
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
