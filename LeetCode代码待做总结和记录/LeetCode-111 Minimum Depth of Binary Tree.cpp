/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //���͵ݹ��㷨�������ж�ʲô��Ҳ�ܺ���⣬Ѱ��ÿһ����������С���������շ��صĽ�������������С������ʱ�临�Ӷ�ΪO(n) 
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
//��������ջʵ�ֵ�bfs��dfs�ĵ�������ʵҲ�ǣ���ÿһ���ڵ���м��� 
//dfsʵ�� ��ʱ��ռ临�Ӷȶ�ΪO(n) 
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
                mindepth=min(mindepth,curdep);//�����curdepһ�����ܼ�һ��������һ�� 
            }
            if(root->left) st.push(make_pair(root->left,curdep+1));
            if(root->right) st.push(make_pair(root->right,curdep+1));
        }
        return mindepth;
    }
};
//bfsʵ�֣���������һ����һ��Ҷ�ӽ��ʱ��ֹͣ������bfs�õ���queueʵ�֣��Ͳ�Ҫ����Ĳõ���stackʵ���� 
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

