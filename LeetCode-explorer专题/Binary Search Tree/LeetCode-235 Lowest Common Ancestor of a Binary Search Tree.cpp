/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 ��������ǿ����õݹ�����⣬��������������Ŀ�и������ӣ����ڶ������������ص�����<��<�ң����Ը��ڵ��ֵһֱ�����м�ֵ��
 ���������������нڵ�ֵ��С�������������нڵ�ֵ����ô���ǿ��������µ��жϣ�������ڵ��ֵ����p��q֮��Ľϴ�ֵ��˵��p��
 q�����������У���ô��ʱ���Ǿͽ�����ڵ�����ӽڵ�����ݹ飬������ڵ�С��p��q֮��Ľ�Сֵ��˵��p��q�����������У���ô
 ��ʱ���Ǿͽ�����ڵ�����ӽڵ�����ݹ飬��������ǣ���˵����ǰ���ڵ������С��ͬ���ڵ㣬ֱ�ӷ��ؼ��ɣ��μ��������£�
 */ 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val >p->val && root->val >q->val) return lowestCommonAncestor(root->left,p,q);
        else if(root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};
/*
��Ȼ������Ҳ�зǵݹ��д�����ø�whileѭ��������ݹ���ü��ɣ�Ȼ��ͣ�ĸ��µ�ǰ�ĸ��ڵ㣬Ҳ��ʵ��ͬ����Ч�����������£�
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        while((root->val<p->val&&root->val<q->val)||(root->val>p->val&&root->val>q->val))
        {
            if(root->val>p->val&&root->val>q->val) root=root->left;
            else if(root->val<p->val&&root->val<q->val) root=root->right;
            //else break;
        }
        return root;
    }
};
//
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        while(true)
        {
            if(root->val>p->val&&root->val>q->val) root=root->left;
            else if(root->val<p->val&&root->val<q->val) root=root->right;
            else break;
        }
        return root;
    }
};
