/*
既然是遍历，就有递归和非递归两种方法，最好两种方法都要掌握，都要会写。下面先来看递归的解法，由于是完全二叉树，
所以若节点的左子结点存在的话，其右子节点必定存在，所以左子结点的next指针可以直接指向其右子节点，对于其右子节
点的处理方法是，判断其父节点的next是否为空，若不为空，则指向其next指针指向的节点的左子结点，若为空则指向NULL，
代码如上： 
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
// Non-recursion, more than constant space,这个迭代的关键地方是在第35行的push了一个NULL这样，只要遇到NULL就说明一行已经结束了，可以对，每行进行区分 
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

