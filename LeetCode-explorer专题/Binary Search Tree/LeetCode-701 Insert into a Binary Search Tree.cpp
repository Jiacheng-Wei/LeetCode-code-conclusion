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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insert(root,val);
        return root;
    }
    void insert(TreeNode*& root, int val){
        if (!root) {
            root=new TreeNode(val);
            return;
        }
        if(root->val==val) return;
        if(val<root->val)  {
            insert(root->left,val);
        }
        else insert(root->right,val);
    }
};
//方法一样
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)
            return new TreeNode(val);
        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        else
            root->val = val;
        return root;
    }
};
//iteration
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode *curr = root, *dummy = new TreeNode(0), *prev = dummy;
        dummy->left = curr;        
        while (curr) {
            if (curr->val > val) {
                prev = curr;
                curr = curr->left;
                if (!curr) prev->left = new TreeNode(val);
            } else {
                prev = curr;
                curr = curr->right;
                if (!curr) prev->right = new TreeNode(val);
            }
        }
        return dummy->left;
    }
}; 
