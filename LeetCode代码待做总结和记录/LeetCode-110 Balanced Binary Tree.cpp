//��ƽ��������Ķ��壺a binary tree in which the depth of the two subtrees of everynode never differ by more than 1.
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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(getdepth(root->left)-getdepth(root->right))>1) return false;
        return isBalanced(root->right)&&isBalanced(root->left);
    }
    int getdepth(TreeNode* root)
    {
        if(!root) return 0;
        return 1+max(getdepth(root->left),getdepth(root->right));
    }
};
/*
�߶�ƽ���������ÿһ������������������Ȳ�ܳ���1����ô���ǿ϶���Ҫһ�����������ȵĺ�����Ȼ���ÿ���ڵ������
�������Ƚ���Ȳʱ�临�Ӷ�ΪO(NlgN)���������ϣ�
������ȷ�����Ǻܸ�Ч����Ϊÿһ���㶼�ᱻ����ĵ�������ʱ����һ�Σ����ǿ��Խ����Ż���������������Ƿ���������ƽ�⣬
�򲻼���������ȣ�����ֱ�ӷ���-1����ô�Ż���ķ���Ϊ������ÿһ���ڵ㣬����ͨ��checkDepth�����ݹ���������������ȣ�
���������ƽ��ģ��򷵻���ʵ����ȣ�����ƽ�⣬ֱ�ӷ���-1���˷���ʱ�临�Ӷ�O(N)���ռ临�Ӷ�O(H)���μ��������� 
*/ 
class Solution {
public:    
    bool isBalanced(TreeNode *root) {
        if (checkDepth(root) == -1) return false;
        else return true;
    }
    int checkDepth(TreeNode *root) {
        if (!root) return 0;
        int left = checkDepth(root->left);
        if (left == -1) return -1;
        int right = checkDepth(root->right);
        if (right == -1) return -1;
        int diff = abs(left - right);
        if (diff > 1) return -1;
        else return 1 + max(left, right);
    }
};
