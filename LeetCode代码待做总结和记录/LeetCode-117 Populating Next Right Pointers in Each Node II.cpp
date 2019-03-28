/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 /*
 ԭ������ȫ�������������������㣬���������˼·���Ǻ����ƣ���Ȼ�еݹ�ͷǵݹ�Ľⷨ�������������ݹ�Ľⷨ���������������п��ܲ�ȱ������Ҫƽ��
 ɨ�踸�ڵ�ͬ��Ľڵ㣬�ҵ����ǵ������ӽڵ㡣�������£� 
 �ݹ�Ĵ��������������һ��Ҫע����ǣ�һ��Ҫע��whileѭ��������ж�˳���Ӱ�����ִ�н����Ҳ����⣬ֻ�д����������α�����˳�������ȷ��
 ͬʱ������ݹ��˳��Ҳ��Ӱ�����յĽ������������δ֪�����ǿ����ս��������ײ�ļ����ڵ������⡣ 
           2
       /      \
      4        3
    / \       / \
   0   7     9   1
 /   / \        / \
5  12   6      8   11
       /
     10
������������7��9�ڵ㣬����9û���ӽڵ㣬����tricky����������ȵݹ����ӽڵ㣬��ô���ݹ鵽�ڵ�7ʱ���ұ߽ڵ�9��next��û�������ұߵĽڵ�1��
��ô�ڵ�7�����ӽڵ�6��next��ֻ��NULL, �������ұߵĽڵ�8����ͳ����ˡ�����������ȵݹ����ӽڵ㣬�Ͳ�����������⡣
 */ 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode* p=root->next;
        while(p)
        {
            if(p->left)
            {
                p=p->left;
                break;
            }
            if(p->right)
            {
                p=p->right;
                break;
            }
            p=p->next;
        }
        
        if(root->left) root->left->next=root->right?root->right:p;
        if(root->right) root->right->next=p;
        connect(root->right);
        connect(root->left);
    }
};
/*
֮ǰ��ĵ�����������ֱ���ã���Ϊ�������Ƿֲ�������Ƿ�Ϊ��ȫ����������Ӱ���� 
*/
// Non-recursion, more than constant space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                TreeLinkNode *t = q.front(); q.pop();
                if (i < len - 1) t->next = q.front();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
    }
};
/*
��Ȼ���ϵ����ַ�������ͨ��OJ������ʵ���Ƕ���������Ŀ��Ҫ����Ŀ˵ֻ��ʹ��constant space������OJȴ
û��дר�ż��spaceʹ�������test����ô��������constant space�Ľⷨ������ⷨҲ���õĲ��������ֻ��
��û��ʹ��queue�ˣ����ǽ���һ��dummy�����ָ��ÿ����׽���ǰһ����㣬Ȼ��ָ��t����������һ�㣬����
ʵ�����Ǳ���һ�㣬Ȼ������һ���next�����ȴӸ���㿪ʼ��������ӽ����ڣ���ôt��next�������ӽ�㣬Ȼ
��tָ����nextָ�룻���root�����ӽ����ڣ���ôt��next�������ӽ�㣬Ȼ��tָ����nextָ�롣��ʱroot����
���ӽ�㶼�����ˣ���ʱroot����ƽ��һλ��ָ����nextָ�룬�����ʱroot�������ˣ�˵����ǰ���Ѿ��������ˣ�
��������tΪdummy��㣬root��ʱΪdummy->next������һ����׽�㣬Ȼ��dummy��nextָ����գ�����Ҳ���Խ�t��nextָ
����գ���Ϊǰ���Ѿ���t��ֵΪdummy�ˡ���ô������һ�룬ΪʲôҪ��գ���Ϊ������dummy��Ŀ�ľ���Ҫֱ����һ�е���
����λ�ü�dummy->next����һ����root��ֵΪdummy->next��֮�����dummy��ʹ�����Ѿ�����ˣ�����Ҫ�Ͽ��������
�Ͽ��Ļ�����ô��������root��Ҷ����ˣ���ôwhileѭ������ִ�У��������ǰ����if��Ȼ��root���Ƹ���֮�󣬻������
��һ��if��֮ǰû�жϿ�dummy->next�Ļ�����ôroot��ָ��֮ǰ��Ҷ����ˣ���ѭ�������ˣ����ˡ�����һ��Ҫ�ǵ����Ŷ��
�Ǻ��ա��������£�
*/
// Non-recursion, constant space
/*
�������������������dummyʼ��Ϊͷ��㣬ԭ��������t��ʼ�ǵ���dummy������ָ��ͬһ��λ�ã����ԣ�dummy�൱����һ����׵�ַ����ʱroot=dummy->next
�ͺý����� 
*/ 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *dummy = new TreeLinkNode(0), *t = dummy;
        while (root) {
            if (root->left) {
                t->next = root->left;
                t = t->next;
            }
            if (root->right) {
                t->next = root->right;
                t = t->next;
            }
            root = root->next;
            if (!root) {
                t = dummy;
                root = dummy->next;
                dummy->next = NULL;
            }
        }
    }
};
