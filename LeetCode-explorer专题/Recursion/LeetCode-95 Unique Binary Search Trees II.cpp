/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //递归的方法求解该问题，然后具体方法也就是按照卡特兰树的方法，不停的划分左右子树然后获得所有树的构建 
class Solution {
public:
    vector<TreeNode*>genetree(int start,int end)
    {
        vector<TreeNode*> all_trees;
        if(start>end)
        {
            all_trees.push_back(NULL);
            return all_trees;
        }
        for (int i=start;i<=end;i++)
        {
            vector<TreeNode*> left_trees=genetree(start,i-1);
            vector<TreeNode*> right_trees=genetree(i+1,end);
            for(TreeNode* l:left_trees)
            {
                for(TreeNode* r:right_trees)
                {
                    TreeNode* cur_tree=new TreeNode(i);
                    cur_tree->left=l;
                    cur_tree->right=r;
                    all_trees.push_back(cur_tree);
                }
            }
        }
        return all_trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode*>();
        return genetree(1,n);
    }
};
//还有dp的方法，后面总结 
