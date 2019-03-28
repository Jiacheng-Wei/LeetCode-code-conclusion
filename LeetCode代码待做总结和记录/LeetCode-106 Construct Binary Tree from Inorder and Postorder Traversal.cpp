//特别注意，题里面有一个条件是没有重复元素，若有重复元素会存在多解 
/*
针对这道题，由于后序的顺序的最后一个肯定是根，所以原二叉树的根节点可以知道，题目中给了一个很关键的条件就是树中没有相同元素，
有了这个条件我们就可以在中序遍历中也定位出根节点的位置，并以根节点的位置将中序遍历拆分为左右两个部分，分别对其递归调用原函数。
上述代码中需要小心的地方就是递归是postorder的左右index很容易写错，比如 pLeft + i - iLeft - 1, 这个又长又不好记，首先我们要记住 
i - iLeft 是计算inorder中根节点位置和左边起始点的距离，然后再加上postorder左边起始点然后再减1。我们可以这样分析，如果根节点就
是左边起始点的话，那么拆分的话左边序列应该为空集，此时i - iLeft 为0， pLeft + 0 - 1 < pLeft, 那么再递归调用时就会返回NULL, 成立。
如果根节点是左边起始点紧跟的一个，那么i - iLeft 为1， pLeft + 1 - 1 = pLeft，再递归调用时还会生成一个节点，就是pLeft位置上的节点，
为原二叉树的一个叶节点。

我们下面来看一个例子, 某一二叉树的中序和后序遍历分别为：

Inorder:　　 　11　　4　　5　　13　　8　　9

Postorder:　　11　　4　　13　　9　　8　　5　　

 

11　　4　　5　　13　　8　　9　　　　　　=>　　　　　　　　　   5

11　　4　　13　　9　　8　　5　　　　　　　　　　　　　　　　/　　\

 

11　　4　　 　　13　　 8　　9　　　　　　=>　　　　　　　　　   5

11　　4　　　　 13　　9　　8　　 　　　　　　　　　　　　　  /　　\

　　　　　　　　　　　　　　　　　　　　　　　　　　　　　4　　　   8

 

11　　　　 　　13　　　　9　　　　　　　　=>　　　　　　　　　   5

11　　　　　　 13　　　　9　　　　 　　　　　　　　　　　　   /　　\

　　　　　　　　　　　　　　　　　　　　　　　　　　　　　4　　　    8

　　　　　　　　　　　　　　　　　　　　　　　　　　　　/　　　    /     \

　　　　　　　　　　　　　　　　　　　　　　　　　　　11　　     13　　   9
*/ 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &inorder, int iLeft, int iRight, vector<int> &postorder, int pLeft, int pRight) {
        if (iLeft > iRight || pLeft > pRight) return NULL;
        TreeNode *cur = new TreeNode(postorder[pRight]);
        int i = 0;
        for (i = iLeft; i < inorder.size(); ++i) {
            if (inorder[i] == cur->val) break;
        }
        cur->left = buildTree(inorder, iLeft, i - 1, postorder, pLeft, pLeft + i - iLeft - 1);//注意这里一定是pleft+i-ileft-1 
        cur->right = buildTree(inorder, i + 1, iRight, postorder, pLeft + i - iLeft, pRight - 1);//注意这里一定是pleft+i-1 
        return cur;
    }
};
//该题和上一个题类似，不过只是，从先序换成了后序，然后循环的和递归的参数改变了而已，最终思路是一样的 
