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
    TreeNode* deleteNode(TreeNode* root, int key) {
        deleteN(root,key);
        return root;
    }
    TreeNode* findMax(TreeNode* root)
    {
        while(root->right){
            root=root->right;
        }
        return root;
    }
    TreeNode* findMin(TreeNode* root){
        while(root->left){
            root=root->left;
        }
        return root;
    }
    void deleteN(TreeNode*& root,int key)
    {
        if(!root) return;
        if(root->val==key)
        {
            if(!root->left&&!root->right) root=NULL;
            else if(root->right){
                TreeNode* next=findMin(root->right);
                root->val=next->val;
                deleteN(root->right,next->val);
            }
            else{
                TreeNode* pre=findMax(root->left);
                root->val=pre->val;
                deleteN(root->left,pre->val);
            }
        }
        else if(root->val>key){
            deleteN(root->left,key);
        }
        else{
            deleteN(root->right,key);
        }
    }
};
