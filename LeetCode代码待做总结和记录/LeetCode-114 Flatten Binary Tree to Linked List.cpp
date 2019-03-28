/*
�����Ҫ��Ѷ�����չ������������չ�����γɵ������˳���������ʹ�������������ôֻҪ�����ı������еݹ�ͷǵݹ�
�����ַ�������⣬��������Ҳ�����ַ�������⡣���������ݹ�汾�ģ�˼·��������DFS��˼·�ҵ������ӽڵ㣬Ȼ��ص�
�丸�ڵ㣬���丸�ڵ�����ӽڵ�Ͽ�����ԭ���ӽ�����ϸ��ڵ�����ӽڵ��ϣ�Ȼ���ٰ�ԭ���ӽڵ����������ӽڵ�����ӽ�
���ϣ�Ȼ���ٻص���һ���ڵ�����ͬ�������������£�
*/ 
// Recursion
class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right) root = root->right;
        root->right = tmp;
    }
};
//���ǶԵݹ��һ���޸ģ��Ҿ��õ���Ҷ�ӽ��ʱ�Ͳ�����ִ�к���Ĳ����ˣ�Ӧ��ֱ�ӷ��أ�����Լʱ�䣬�൱�ڼ�֦
class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root||(!root->right&&!root->left)) return;
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right) root = root->right;
        root->right = tmp;
    }
}; 
/*
�任���̾��Ǵ���ײ��������ʼ�����������ӵ����������棬����һ��һ�����ϵݹ� https://www.cnblogs.com/grandyang/p/4293853.html
*/ 
/*
�����ķ���ʵ�֣������ʵ�ּ��£���������ǴӸ��ڵ㿪ʼ�������ȼ�������ӽ���Ƿ���ڣ�������򽫸��ڵ�������ӽڵ�Ͽ��������ӽ�㼰��������н�
��һ������ԭ���ӽڵ��λ�ã���ԭ���ӽڵ�����Ԫ���ӽ�����������ӽڵ�֮�󡣴������£�
*/ 
class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *p = cur->left;
                while (p->right) p = p->right;
                p->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};
/*
������������ǰ�����������һ�ַ������ƣ�ֻ������stack���洢���е��������ڵ���� 
*/ 
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *t = s.top(); s.pop();
            if (t->left) {
                TreeNode *r = t->left;
                while (r->right) r = r->right;
                r->right = t->right;
                t->right = t->left;
                t->left = NULL;
            }
            if (t->right) s.push(t->right);
        }
    }
};
