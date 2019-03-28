/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //AVL树的建法 
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=NULL;
        for(int i=0;i<nums.size();i++){
            insert(root,nums[i]);
        }
        return root;
    }
    int getheight(TreeNode* root){
        if(!root) return 0;
        return max(getheight(root->right),getheight(root->left))+1;
    }
    int getBF(TreeNode* root){
        return getheight(root->left)-getheight(root->right);
    }
    void L(TreeNode* &root){
        TreeNode* temp=root->right;
        root->right=temp->left;
        temp->left=root;
        root=temp;
    }
    void R(TreeNode* &root){
        TreeNode* temp=root->left;
        root->right=temp->right;
        temp->right=root;
        root=temp;
    }
    void insert(TreeNode* &root,int v){
        if(!root) {
            root=new TreeNode(v);
            return;
        }
        if(v<root->val){
            insert(root->left,v);
            if(getBF(root)==2){
                if(getBF(root->left)==1) R(root);
                else if(getBF(root->left)==-1) {
                    L(root->left);
                    R(root);
                }
            }
        }
        else {
            insert(root->right,v);
            if(getBF(root)==-2){
                if(getBF(root->right)==-1) L(root);
                else if(getBF(root->right)==1)
                {
                    R(root->right);
                    L(root);
                }
            }
        }
    }
};
//简单建法，即从中间开始建树
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums,0,nums.size()-1);
    }
    TreeNode *buildTree(vector<int>& nums, int left,int right)
    {
        if(left>right) return NULL;
        int mid=left+(right-left)/2;
        TreeNode *cur=new TreeNode(nums[mid]);
        cur->left=buildTree(nums,left,mid-1);
        cur->right=buildTree(nums,mid+1,right);
        return cur;
    }
}; 
