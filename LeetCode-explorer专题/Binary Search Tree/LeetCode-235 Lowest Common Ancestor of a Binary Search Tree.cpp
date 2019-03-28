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
 这道题我们可以用递归来求解，我们首先来看题目中给的例子，由于二叉搜索树的特点是左<根<右，所以根节点的值一直都是中间值，
 大于左子树的所有节点值，小于右子树的所有节点值，那么我们可以做如下的判断，如果根节点的值大于p和q之间的较大值，说明p和
 q都在左子树中，那么此时我们就进入根节点的左子节点继续递归，如果根节点小于p和q之间的较小值，说明p和q都在右子树中，那么
 此时我们就进入根节点的右子节点继续递归，如果都不是，则说明当前根节点就是最小共同父节点，直接返回即可，参见代码如下：
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
当然，此题也有非递归的写法，用个while循环来代替递归调用即可，然后不停的更新当前的根节点，也能实现同样的效果，代码如下：
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
