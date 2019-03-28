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
/*
迭代的方法解决问题，用栈实现，但是用栈实现要注意的问题是要从子树的最右边的孩子节点入栈，只有这样才能实现前序遍历 
*/ 
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        stack<Node*> temp;
        temp.push(root);
        while(!temp.empty())
        {
            Node* tmp=temp.top();
            res.push_back(tmp->val);
            temp.pop();
            for(int i=tmp->children.size()-1;i>=0;i--)
            {
                temp.push(tmp->children[i]);
            }
        }
        return res;
    }
};
/*
递归的实现方法：需要单独写一个递归函数，避免res数组重复创建 
*/ 
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root)
        {
            recursive(res,root);
        }
        return res;
    }
    void recursive(vector<int>& res, Node* root)
    {
        if(root)
        {
            res.push_back(root->val);
            for(auto n:root->children)
            {
                recursive(res,n);
            }
        }
    }
};
