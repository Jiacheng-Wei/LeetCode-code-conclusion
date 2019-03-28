/*
这道题要求把二叉树展开成链表，根据展开后形成的链表的顺序分析出是使用先序遍历，那么只要是数的遍历就有递归和非递归
的两种方法来求解，这里我们也用两种方法来求解。首先来看递归版本的，思路是先利用DFS的思路找到最左子节点，然后回到
其父节点，把其父节点和右子节点断开，将原左子结点连上父节点的右子节点上，然后再把原右子节点连到新右子节点的右子节
点上，然后再回到上一父节点做相同操作。代码如下：
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
//这是对递归的一点修改，我觉得当到叶子结点时就不用在执行后面的步骤了，应该直接返回，更节约时间，相当于剪枝
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
变换过程就是从最底层的子树开始将做子树连接到右子树下面，这样一层一层向上递归 https://www.cnblogs.com/grandyang/p/4293853.html
*/ 
/*
迭代的方法实现，具体的实现见下，这个方法是从根节点开始出发，先检测其左子结点是否存在，如存在则将根节点和其右子节点断开，将左子结点及其后面所有结
构一起连到原右子节点的位置，把原右子节点连到元左子结点最后面的右子节点之后。代码如下：
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
迭代方法二：前序迭代，和上一种方法类似，只是用了stack来存储所有的右子树节点而已 
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
