/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//层序遍历注意题目要求，是通过输入输出流实现，原因是要存储在内存和文件中，所以要注意题目要求 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        string res;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();
            if(t)
            {
                out<<t->val<<' ';
                q.push(t->left);
                q.push(t->right);
            }
            else out<<"# ";
        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        istringstream in(data);
        queue<TreeNode*> res;
        string val;
        in>> val;
        TreeNode *temp=new TreeNode(stoi(val));
        TreeNode *cur=temp;
        res.push(cur);
        while(!res.empty())
        {
            TreeNode *t=res.front();
            res.pop();
            if(!(in>>val)) break;
            if(val!="#")
            {
                cur=new TreeNode(stoi(val));
                res.push(cur);
                t->left=cur;
            }
            if(!(in>>val)) break;
            if(val!="#")
            {
                cur=new TreeNode(stoi(val));
                res.push(cur);
                t->right=cur;
            }
        }
        return temp;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
