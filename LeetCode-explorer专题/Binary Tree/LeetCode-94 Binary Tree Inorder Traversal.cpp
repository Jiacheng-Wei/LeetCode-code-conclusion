/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //递归的方法解决这个问题，中序遍历就是先左后中再右，按次序遍历，递归的方法就是不断的先处理左支树，再是中，再是右 ，时间复杂度是O(n) 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        generate(root,res);
        return res;
            
    }
    void generate(TreeNode* root,vector<int>& res)
    {
        if(root!=NULL)
        {
            if(root->left!=NULL)
            {
                generate(root->left,res);
            }
            res.push_back(root->val);
            if(root->right!=NULL)
            {
                generate(root->right,res);
            }
        }
    }
};
//借用栈来解决问题, 时间复杂度为O(n) 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr=root;
        while (curr!=NULL||!st.empty())
        {
            while (curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            res.push_back(curr->val);
            curr=curr->right;//这里一定要是curr=curr->left,自己画图理解就是既使是右节点，但是也会在第二个while循环中作为root节点压入栈 
        }
        return res;
    }
};
//线索二叉树方法。时间复杂度为O(n)，详细方法，可以见本题的solution和https://www.cnblogs.com/grandyang/p/4297300.html 博客 
/*
Step 1: Initialize current as root

Step 2: While current is not NULL,

If current does not have left child

    a. Add current’s value

    b. Go to the right, i.e., current = current.right
Else
    a. In current's left subtree, make current the right child of the rightmost node//让curr指针成为左子树中最右子树的右子树 
    b. Go to this left child, i.e., current = current.left
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr=root;
        TreeNode* pre;
        while (curr!=NULL)
        {
            if(curr->left==NULL)
            {
                res.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                pre=curr->left;
                while (pre->right!=NULL)
                {
                    pre=pre->right;
                }
                pre->right=curr;
                TreeNode* temp=curr;
                curr=curr->left;
                temp->left=NULL;
            }
        }
        return res;
    }
}; 
 
