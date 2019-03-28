/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //Recursive solution 
class Solution {
public:
    void solve(vector<int>& res,TreeNode* root)
    {
        if(root!=NULL) res.push_back(root->val);
        if(root->left) solve(res,root->left);
        if(root->right) solve(res,root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        solve(res,root);
        return res;
    }
};
//iterative solution
/*
��Ŀ��Ҫ���ǲ���ʹ�õݹ���⣬����ֻ�ܿ��ǵ��÷ǵݹ�ķ��������Ҫ�õ�stack���������㡣�������������˳����"��-��-��", �㷨Ϊ��
1. �Ѹ��ڵ�push��ջ��
2. ѭ�����ջ�Ƿ�Ϊ�գ������գ���ȡ��ջ��Ԫ�أ�������ֵ��Ȼ�������ӽڵ��Ƿ���ڣ���������push��ջ�С��ٿ������ӽڵ㣬�����ڣ�
��push��ջ�С�
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* t=st.top();
            st.pop();
            res.push_back(t->val);
            if(t->right) st.push(t->right);
            if(t->left) st.push(t->left);
        }
        return res;
    }
};
/*
��������д��ʹ����һ���������p������д����ʵ���Կ�����һ��ģ�棬��Ӧ�Ļ�������ͺ����ģ��д������ʽ��ͳһ�������ڼ��䡣�������p��ʼ��Ϊ
����㣬whileѭ����������ջ��Ϊ�ջ��߸������p��Ϊ�գ���ѭ���������ж�����������p���ڣ���ô�Ƚ�p����ջ�У�Ȼ��p�Ľ��ֵ������res�У�
��ʱpָ�������ӽ�㡣�������p�����ڵĻ�������û�����ӽ�㣬����ȡ��ջ����㣬��pָ��ջ���������ӽ�㣬�μ��������£�
*/ 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* p=root;
        while(!st.empty()||p)
        {
            if(p)
            {
                res.push_back(p->val);
                st.push(p);
                p=p->left;
            }
            else
            {
                TreeNode* t=st.top();
                st.pop();
                p=t->right;
            }
        }
        return res;
    }
}; 

