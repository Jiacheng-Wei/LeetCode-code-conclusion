/*
��Ȼ�Ǳ��������еݹ�ͷǵݹ����ַ�����������ַ�����Ҫ���գ���Ҫ��д�������������ݹ�Ľⷨ����������ȫ��������
�������ڵ�����ӽ����ڵĻ��������ӽڵ�ض����ڣ��������ӽ���nextָ�����ֱ��ָ�������ӽڵ㣬���������ӽ�
��Ĵ������ǣ��ж��丸�ڵ��next�Ƿ�Ϊ�գ�����Ϊ�գ���ָ����nextָ��ָ��Ľڵ�����ӽ�㣬��Ϊ����ָ��NULL��
�������ϣ� 
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        if(root->left) root->left->next=root->right;
        if(root->right) root->right->next=root->next? root->next->left:NULL;
        connect(root->left);
        connect(root->right);
    }
};
/*

*/
// Non-recursion, more than constant space,��������Ĺؼ��ط����ڵ�35�е�push��һ��NULL������ֻҪ����NULL��˵��һ���Ѿ������ˣ����Զԣ�ÿ�н������� 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        while (true) {
            TreeLinkNode *cur = q.front();
            q.pop();
            if (cur) {
                cur->next = q.front();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            } else {
                if (q.size() == 0 || q.front() == NULL) return;
                q.push(NULL);
            }
        }
    }
};

