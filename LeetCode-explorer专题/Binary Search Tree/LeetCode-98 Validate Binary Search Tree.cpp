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
利用它本身的性质来做，即左<根<右，也可以通过利用中序遍历结果为有序数列来做，下面我们先来看最简单的一种，
就是利用其本身性质来做，初始化时带入系统最大值和最小值，在递归过程中换成它们自己的节点值，用long代替int
就是为了包括int的边界条件，代码如下：
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
因为有的时候题目中的二叉搜索树会定义为左<=根<右，而这道题设定为一般情况左<根<右，那么就可以用中序遍历来做。
因为如果不去掉左=根这个条件的话，那么下边两个数用中序遍历无法区分：

   20       20
   /           \
 20           20

它们的中序遍历结果都一样，但是左边的是BST，右边的不是BST。去掉等号的条件则相当于去掉了这种限制条件。下
面我们来看使用中序遍历来做，这种方法思路很直接，通过中序遍历将所有的节点值存到一个数组里，然后再来判断这
个数组是不是有序的，代码如下：因为有的时候题目中的二叉搜索树会定义为左<=根<右，而这道题设定为一般情况左<根<右，
那么就可以用中序遍历来做。因为如果不去掉左=根这个条件的话，那么下边两个数用中序遍历无法区分：

   20       20
   /           \
 20           20

它们的中序遍历结果都一样，但是左边的是BST，右边的不是BST。去掉等号的条件则相当于去掉了这种限制条件。
下面我们来看使用中序遍历来做，这种方法思路很直接，通过中序遍历将所有的节点值存到一个数组里，然后再
来判断这个数组是不是有序的，代码如下：
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
下面这种解法跟上面那个很类似，都是用递归的中序遍历，但不同之处是不将遍历结果存入一个数组遍历完成再比较，
而是每当遍历到一个新节点时和其上一个节点比较，如果不大于上一个节点那么则返回false，全部遍历完成后返回true。
代码如下：
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
当然这道题也可以用非递归来做，需要用到栈，因为中序遍历可以非递归来实现，所以只要在其上面稍加改动便可，代码如下：
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
