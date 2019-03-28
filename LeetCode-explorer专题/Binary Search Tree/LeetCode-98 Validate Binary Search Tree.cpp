/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
�������������������������<��<�ң�Ҳ����ͨ����������������Ϊ������������������������������򵥵�һ�֣�
���������䱾��������������ʼ��ʱ����ϵͳ���ֵ����Сֵ���ڵݹ�����л��������Լ��Ľڵ�ֵ����long����int
����Ϊ�˰���int�ı߽��������������£�
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return judge(root,LONG_MIN,LONG_MAX);
    }
    bool judge(TreeNode* root,long mn,long mx)
    {
        if(!root) return true;
        if(root->val<=mn||root->val>=mx) return false;
        return judge(root->left,mn,root->val)&&judge(root->right,root->val,mx);
    }
};
/*
��Ϊ�е�ʱ����Ŀ�еĶ����������ᶨ��Ϊ��<=��<�ң���������趨Ϊһ�������<��<�ң���ô�Ϳ������������������
��Ϊ�����ȥ����=����������Ļ�����ô�±�����������������޷����֣�

   20       20
   /           \
 20           20

���ǵ�������������һ����������ߵ���BST���ұߵĲ���BST��ȥ���Ⱥŵ��������൱��ȥ��������������������
����������ʹ������������������ַ���˼·��ֱ�ӣ�ͨ��������������еĽڵ�ֵ�浽һ�������Ȼ�������ж���
�������ǲ�������ģ��������£���Ϊ�е�ʱ����Ŀ�еĶ����������ᶨ��Ϊ��<=��<�ң���������趨Ϊһ�������<��<�ң�
��ô�Ϳ��������������������Ϊ�����ȥ����=����������Ļ�����ô�±�����������������޷����֣�

   20       20
   /           \
 20           20

���ǵ�������������һ����������ߵ���BST���ұߵĲ���BST��ȥ���Ⱥŵ��������൱��ȥ������������������
������������ʹ������������������ַ���˼·��ֱ�ӣ�ͨ��������������еĽڵ�ֵ�浽һ�������Ȼ����
���ж���������ǲ�������ģ��������£�
*/
// Recursion
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        vector<int> vals;
        inorder(root, vals);
        for (int i = 0; i < vals.size() - 1; ++i) {
            if (vals[i] >= vals[i + 1]) return false;
        }
        return true;
    }
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
};
/*
�������ֽⷨ�������Ǹ������ƣ������õݹ���������������֮ͬ���ǲ��������������һ�������������ٱȽϣ�
����ÿ��������һ���½ڵ�ʱ������һ���ڵ�Ƚϣ������������һ���ڵ���ô�򷵻�false��ȫ��������ɺ󷵻�true��
�������£�
*/ 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *pre = NULL;
        return inorder(root, pre);
    }
    bool inorder(TreeNode* node, TreeNode*& pre) {
        if (!node) return true;
        bool res = inorder(node->left, pre);
        if (!res) return false;
        if (pre) {
            if (node->val <= pre->val) return false;
        }
        pre = node;
        return inorder(node->right, pre);
    }
};
/*
��Ȼ�����Ҳ�����÷ǵݹ���������Ҫ�õ�ջ����Ϊ����������Էǵݹ���ʵ�֣�����ֻҪ���������ԼӸĶ���ɣ��������£�
*/ 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *p = root, *pre = NULL;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            if (pre && p->val <= pre->val) return false;
            pre = p;
            p = p->right;
        }
        return true;
    }
};
