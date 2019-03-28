/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //�ݹ�ķ������������⣬���������������������ң�������������ݹ�ķ������ǲ��ϵ��ȴ�����֧���������У������� ��ʱ�临�Ӷ���O(n) 
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
//����ջ���������, ʱ�临�Ӷ�ΪO(n) 
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
            curr=curr->right;//����һ��Ҫ��curr=curr->left,�Լ���ͼ�����Ǽ�ʹ���ҽڵ㣬����Ҳ���ڵڶ���whileѭ������Ϊroot�ڵ�ѹ��ջ 
        }
        return res;
    }
};
//����������������ʱ�临�Ӷ�ΪO(n)����ϸ���������Լ������solution��https://www.cnblogs.com/grandyang/p/4297300.html ���� 
/*
Step 1: Initialize current as root

Step 2: While current is not NULL,

If current does not have left child

    a. Add current��s value

    b. Go to the right, i.e., current = current.right
Else
    a. In current's left subtree, make current the right child of the rightmost node//��currָ���Ϊ������������������������ 
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
 
