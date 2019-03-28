/*
�������Ҫ����������תΪ��������������ν��������������һ��ʼ��������<��<�ҵ����ԣ��������������������������Ļ���
�õ��ľ���һ�����������ˡ���ô�����������ǿ��Ե�֪�����ڵ�Ӧ��������������м�㣬���м��ֿ�Ϊ���������������飬
�ڷֱ��ҳ����м����Ϊԭ�м������������ӽڵ㣬�ⲻ�����Ƕ��ֲ��ҷ��ĺ���˼��ô����������⿼�ľ��Ƕ��ֲ��ҷ����������£�
*/   
//ע����������и��Ⱦ��������������������������balanced-height�ģ������������ĸ߶Ȳ����һ�������м��Ҳ��һ����root�ڵ�
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
 
