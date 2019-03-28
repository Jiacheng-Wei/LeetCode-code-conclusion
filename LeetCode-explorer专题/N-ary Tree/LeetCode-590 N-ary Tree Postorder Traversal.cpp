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
递归的解决问题，要对递归过程理解要深刻，画出递归过程图后理解会简单些，先下探再回溯的过程一定要理解清楚 
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
后序遍历的得到结果的顺序是 左->右->中，我们可以采用中右左的遍历方式，最后把数组取反就可以了。
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
            //取反的过程 
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
