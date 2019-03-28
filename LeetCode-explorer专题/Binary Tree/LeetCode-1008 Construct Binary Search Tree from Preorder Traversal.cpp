/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //����һ�ֺܴ�ͳ�ķ�������û������BST�����ڽ��������е���Խ�ԣ���������Ϊ���д��Ľ� 
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        TreeNode *root=creat(inorder,preorder,0,n-1,0,n-1);
        return root;
    }
    TreeNode* creat(vector<int>& in,vector<int>& pre,int il,int ir,int pl,int pr)
    {
        if(pl>pr) return NULL;
        TreeNode* root= new TreeNode(pre[pl]);
        int k;
        for(k=il;k<ir;k++)
        {
            if(in[k]==pre[pl]) break;
        }
        int numleft=k-il;
        root->left=creat(in,pre,il,k-1,pl+1,pl+numleft);
        root->right=creat(in,pre,k+1,ir,pl+numleft+1,pr);
        return root;
    }
};
//����BST���ʵĽ�����ʽ
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        TreeNode *root=creat(preorder,0,n-1);
        return root;
    }
    TreeNode* creat(vector<int>& pre,int pl,int pr)
    {
        if(pl>pr) return NULL;
        TreeNode* root= new TreeNode(pre[pl]);
        int k;
        for(k=pl;k<=pr;k++)
        {
            if(pre[k]>pre[pl]) break;
        }
        int numleft=k-pl-1;
        root->left=creat(pre,pl+1,pl+numleft);
        root->right=creat(pre,pl+numleft+1,pr);
        return root;
    }  
}; 
