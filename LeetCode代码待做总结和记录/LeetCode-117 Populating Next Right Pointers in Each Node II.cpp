/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 /*
 原本的完全二叉树的条件不再满足，但是整体的思路还是很相似，仍然有递归和非递归的解法。我们先来看递归的解法，这里由于子树有可能残缺，故需要平行
 扫描父节点同层的节点，找到他们的左右子节点。代码如下： 
 递归的处理方法，这个方法一定要注意的是，一定要注意while循环里面的判断顺序会影响程序执行结果，也好理解，只有从左向右依次遍历的顺序才是正确的
 同时，下面递归的顺序也会影响最终的结果，具体的理解未知，但是看最终结果是在最底层的几个节点会出问题。 
           2
       /      \
      4        3
    / \       / \
   0   7     9   1
 /   / \        / \
5  12   6      8   11
       /
     10
问题出在里面的7和9节点，由于9没有子节点，这块很tricky，如果我们先递归左子节点，那么当递归到节点7时，右边节点9的next还没有连上右边的节点1，
那么节点7的右子节点6的next就只能NULL, 而并非右边的节点8，这就出错了。而如果我们先递归右子节点，就不会有这个问题。
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
之前题的迭代方法可以直接用，因为方法都是分层遍历，是否为完全二叉树并不影响结果 
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
虽然以上的两种方法都能通过OJ，但其实它们都不符合题目的要求，题目说只能使用constant space，可是OJ却
没有写专门检测space使用情况的test，那么下面贴上constant space的解法，这个解法也是用的层序遍历，只不
过没有使用queue了，我们建立一个dummy结点来指向每层的首结点的前一个结点，然后指针t用来遍历这一层，我们
实际上是遍历一层，然后连下一层的next，首先从根结点开始，如果左子结点存在，那么t的next连上左子结点，然
后t指向其next指针；如果root的右子结点存在，那么t的next连上右子结点，然后t指向其next指针。此时root的左
右子结点都连上了，此时root向右平移一位，指向其next指针，如果此时root不存在了，说明当前层已经遍历完了，
我们重置t为dummy结点，root此时为dummy->next，即下一层的首结点，然后dummy的next指针清空，或者也可以将t的next指
针清空，因为前面已经将t赋值为dummy了。那么现在想一想，为什么要清空？因为我们用dummy的目的就是要直到下一行的首
结点的位置即dummy->next，而一旦将root赋值为dummy->next了之后，这个dummy的使命就已经完成了，必须要断开，如果不
断开的话，那么假设现在root是叶结点了，那么while循环还会执行，不会进入前两个if，然后root右移赋空之后，会进入最
后一个if，之前没有断开dummy->next的话，那么root又指向之前的叶结点了，死循环诞生了，跪了。所以一定要记得清空哦，
呵呵哒～代码如下：
*/
// Non-recursion, constant space
/*
下面这个方法巧妙在于dummy始终为头结点，原因是在于t初始是等于dummy的由于指向同一个位置，所以，dummy相当于下一层的首地址，此时root=dummy->next
就好解释了 
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
