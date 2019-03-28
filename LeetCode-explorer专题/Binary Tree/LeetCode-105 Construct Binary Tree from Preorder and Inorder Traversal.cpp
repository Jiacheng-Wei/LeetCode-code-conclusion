/*
我们下面来看一个例子, 某一二叉树的中序和后序遍历分别为：

Preorder:　  　5　　4　　11　　8　　13　　9

Inorder:　　 　11　　4　　5　　13　　8　　9

 

5　　4　　11　　8　　13　　9　　　　　　=>　　　　　　　　　   5

11　　4　　5　　13　　8　　9　　　　　　　　　　　　　　　　/　　\

 

4　　11　　 　　8　　 13　　9　　　　　　=>　　　　　　　　　   5

11　　4　　　　 13　　8　　9　　 　　　　　　　　　　　　　  /　　\

　　　　　　　　　　　　　　　　　　　　　　　　　　　　　4　　　   8

 

11　　　　 　　13　　　　9　　　　　　　　=>　　　　　　　　　   5

11　　　　　　 13　　　　9　　　　 　　　　　　　　　　　　   /　　\

　　　　　　　　　　　　　　　　　　　　　　　　　　　　　4　　　   8

　　　　　　　　　　　　　　　　　　　　　　　　　　　　/　　　 /     \

　　　　　　　　　　　　　　　　　　　　　　　　　　　11　　  13　　  9

 

做完这道题后，大多人可能会有个疑问，怎么没有由先序和后序遍历建立二叉树呢，这是因为先序和后序遍历不能唯一的确定一个二叉树，比如下面五棵树：

    1　　　　　　preorder:　　  1　　2　　3
   / \　　　　　  inorder:　　     2　　1　　3
 2    3　　  　　 postorder:　　 2　　3　　1

 

       1   　　　　preorder:　　   1　　2　　3
      / 　　　　　 inorder:　　     3　　2　　1
    2 　　　　     postorder: 　　3　　2　　1
   /
 3

 

       1　　　　    preorder:　　  1　　2　　3
      / 　　　　　  inorder:　　    2　　3　　1
    2 　　　　　　postorder:　　3　　2　　1
      \
       3

 

       1　　　　     preorder:　　  1　　2　　3
         \ 　　　　   inorder:　　    1　　3　　2
          2 　　　　 postorder:　　3　　2　　1
         /
       3

 

       1　　　　     preorder:　　  1　　2　　3
         \ 　　　　　inorder:　　    1　　2　　3
          2 　　　　 postorder:　　3　　2　　1
            \
　　　　     3

 

 从上面我们可以看出，对于先序遍历都为1 2 3的五棵二叉树，它们的中序遍历都不相同，而它们的后序遍历却有相同的，所以只有和中序遍历一起才能
 唯一的确定一棵二叉树。
*/ 
//方法是先通过中序先祖遍历确定root节点，然后在中序遍历中找到root节点，此时将中序遍历分成了左右子树，然后对左右子树进行相同的步骤，这样就建树完成了
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &preorder, int pLeft, int pRight, vector<int> &inorder, int iLeft, int iRight) {
        if (pLeft > pRight || iLeft > iRight) return NULL;//利用index来对两个排列进行左右子树拆分，先定义终止条件 
        int i = 0;
        for (i = iLeft; i <= iRight; ++i) {//这一步是定位root节点在两个排列中的位置 
            if (preorder[pLeft] == inorder[i]) break;
        }
        TreeNode *cur = new TreeNode(preorder[pLeft]);//注意这里生成新节点的格式 
        cur->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
//由于先序排列和中序排列的特点，那么拆分后的左子树的root节点在先序排列中时pleft+1，然后这属于整个左支树的在先序里面的范围是pleft+i-1。
//对于中序排列，左右子树的划分就简单很多了，左子树就是ileft,到i-1位置 
        cur->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
//对于右之树，右子树在先序排列中的起点是就是，pleft加上所有左子树数目后的一个，终点当然是pright，然后对于中序排列中，右子树起点是i+1,终点是iright 
        return cur;//最后一定要return cur 
    }
}; 
//时间复杂度O(n^2) 
