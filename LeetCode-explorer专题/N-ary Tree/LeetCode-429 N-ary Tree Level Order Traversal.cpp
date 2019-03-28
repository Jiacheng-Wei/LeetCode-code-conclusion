/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
//这里一定要记住可以数组长度来控制每一层的遍历 
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > res;
        if(!root) return res;
        queue<Node*> que;
        que.push(root);
        while(!que.empty())
        {
            int len=que.size();
            vector<int> rs;
            for(int i=0;i<len;i++)
            {
                Node* head=que.front();
                que.pop();
                rs.push_back(head->val);
                for(auto n:head->children)
                {
                    que.push(n);
                }
            }
            res.push_back(rs);
        }
        return res;
    }
};
