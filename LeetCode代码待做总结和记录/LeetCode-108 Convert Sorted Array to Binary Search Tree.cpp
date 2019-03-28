/*
这道题是要将有序数组转为二叉搜索树，所谓二叉搜索树，是一种始终满足左<根<右的特性，如果将二叉搜索树按中序遍历的话，
得到的就是一个有序数组了。那么反过来，我们可以得知，根节点应该是有序数组的中间点，从中间点分开为左右两个有序数组，
在分别找出其中间点作为原中间点的左右两个子节点，这不就是是二分查找法的核心思想么。所以这道题考的就是二分查找法，代码如下：
*/   
//注意这个方法有个先决条件，就是这个二叉搜索树是balanced-height的，即左右子树的高度差不大于一，否则中间点也不一定是root节点
//a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
 
