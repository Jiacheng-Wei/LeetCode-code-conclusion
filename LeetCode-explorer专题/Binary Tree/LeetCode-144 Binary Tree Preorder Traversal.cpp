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
题目的要求是不能使用递归求解，于是只能考虑到用非递归的方法，这就要用到stack来辅助运算。由于先序遍历的顺序是"根-左-右", 算法为：
1. 把根节点push到栈中
2. 循环检测栈是否为空，若不空，则取出栈顶元素，保存其值，然后看其右子节点是否存在，若存在则push到栈中。再看其左子节点，若存在，
则push到栈中。
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
下面这种写法使用了一个辅助结点p，这种写法其实可以看作是一个模版，对应的还有中序和后序的模版写法，形式很统一，方便于记忆。辅助结点p初始化为
根结点，while循环的条件是栈不为空或者辅助结点p不为空，在循环中首先判断如果辅助结点p存在，那么先将p加入栈中，然后将p的结点值加入结果res中，
此时p指向其左子结点。否则如果p不存在的话，表明没有左子结点，我们取出栈顶结点，将p指向栈顶结点的右子结点，参见代码如下：
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

