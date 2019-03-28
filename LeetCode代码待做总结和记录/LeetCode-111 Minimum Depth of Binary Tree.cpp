/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //典型递归算法，而且判断什么的也很好理解，寻找每一个子树的最小层数，最终返回的将是整个树的最小层数，时间复杂度为O(n) 
class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if(!root) return 0;
        if((!root->left)&&(!root->right)) return 1;
        int mindepth=INT_MAX;
        if(root->left)
        {
            mindepth=min(mindepth,minDepth(root->left));
        }
        if(root->right)
        {
            mindepth=min(mindepth,minDepth(root->right));
        }
        return mindepth+1;
    }
};
//还有利用栈实现的bfs，dfs的迭代，其实也是，对每一个节点进行计算 
//dfs实现 ，时间空间复杂度都为O(n) 
class Solution {
public:
    int minDepth(TreeNode* root)
    {
        stack<pair<TreeNode*,int> > st;
        if(!root) return 0;
        else st.push(make_pair(root,1));
        int mindepth=INT_MAX;
        while(!st.empty())
        {
            pair<TreeNode*,int> cur=st.top();
            st.pop();
            root=cur.first;
            int curdep=cur.second;
            if(!root->left&&!root->right)
            {
                mindepth=min(mindepth,curdep);//这里的curdep一定不能加一，否则会多一个 
            }
            if(root->left) st.push(make_pair(root->left,curdep+1));
            if(root->right) st.push(make_pair(root->right,curdep+1));
        }
        return mindepth;
    }
};
//bfs实现，当遍历到一个有一个叶子结点时就停止遍历，bfs用的是queue实现，就不要别出心裁的用stack实现了 
class Solution {
public:
    int minDepth(TreeNode* root)
    {
        queue<pair<TreeNode*,int> > q;
        if(!root) return 0;
        else q.push(make_pair(root,1));
        int curdepth=0;
        while(!q.empty())
        {
            pair<TreeNode*,int> cur=q.front();
            q.pop();
            root=cur.first;
            curdepth=cur.second;
            if(!root->left&&!root->right)
            {
                break;
            }
            if(root->left) q.push(make_pair(root->left,curdepth+1));
            if(root->right) q.push(make_pair(root->right,curdepth+1));
        }
        return curdepth;
    }
};

