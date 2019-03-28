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
�����ķ���������⣬��ջʵ�֣�������ջʵ��Ҫע���������Ҫ�����������ұߵĺ��ӽڵ���ջ��ֻ����������ʵ��ǰ����� 
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
�ݹ��ʵ�ַ�������Ҫ����дһ���ݹ麯��������res�����ظ����� 
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
