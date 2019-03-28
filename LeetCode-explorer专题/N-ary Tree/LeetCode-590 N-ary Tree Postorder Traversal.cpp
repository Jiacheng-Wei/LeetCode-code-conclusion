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
�ݹ�Ľ�����⣬Ҫ�Եݹ�������Ҫ��̣������ݹ����ͼ�������Щ������̽�ٻ��ݵĹ���һ��Ҫ������ 
*/ 
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root)
        {
            recursive(res,root);
        }
        return res;
    }
    void recursive(vector<int>&res, Node* root)
    {
        for(auto n:root->children)
        {
           recursive(res,n);
        }
        res.push_back(root->val);
    }
};
/*
��������ĵõ������˳���� ��->��->�У����ǿ��Բ���������ı�����ʽ����������ȡ���Ϳ����ˡ�
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root)
        {
            stack<Node*> s;
            s.push(root);
            while(!s.empty())
            {
                Node *head=s.top();
                s.pop();
                res.push_back(head->val);
                for(auto n:head->children)
                {
                    s.push(n);
                }
            }
            //ȡ���Ĺ��� 
            int len = res.size();
            for (int i = 0; i < len / 2; i++)
            {
                int buf = res[i];
                res[i] = res[len - i - 1];
                res[len - i - 1] = buf;
            }
        }
        return res;
    }
}; 
