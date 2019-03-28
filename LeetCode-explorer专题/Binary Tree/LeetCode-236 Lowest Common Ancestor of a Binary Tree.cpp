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
 ��p��qҪô�ֱ�λ�����������У���ô�������ӽ����õݹ麯������ֱ𷵻�p��q����λ�ã�����ǰ������þ���p��q����С��ͬ����㣬
 ֱ�ӷ��ص�ǰ��㼴�ɣ��������Ŀ�е�����1�������
��p��qͬʱλ�������������������������һ�������left�᷵��p��q�нϸߵ��Ǹ�λ�ã���right�᷵�ؿգ������������շ��طǿյ�left���ɣ�
�������Ŀ�е�����2�����������һ������ǻ᷵��p��q����С����㣬����˵��ǰ�����������е�ĳ��������p��q����С����㣬�ᱻ���ء�
��p��qͬʱλ����������ͬ�����������������һ�������right�᷵��p��q�нϸߵ��Ǹ�λ�ã���left�᷵�ؿգ������������շ��طǿյ�right
���ɣ�����һ������ǻ᷵��p��q����С����㣬����˵��ǰ�����������е�ĳ��������p��q����С����㣬�ᱻ���أ�д���ܼ�࣬�������£�
 */ 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||p==root||q==root) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left&&right) return root;
        return left? left : right;
    }
};
/*
����������Խ����Ż�һ�£������ǰ��㲻Ϊ�գ��ҼȲ���pҲ����q����ô��������ķ�����p��q��λ�þ������������p��qҪô�ֱ�λ�����������У�
Ҫôͬʱλ��������������ͬʱλ����������������Ҫ�Ż���������ǵ�p��qͬʱΪ�����������������У����ҷ��صĽ�㲢����p��q����ô����p��q����
С������ˣ��Ѿ�������ˣ��Ͳ����ٶ��ҽ����õݹ麯���ˣ��μ��������£�
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (!root || p == root || q == root) return root;
       TreeNode *left = lowestCommonAncestor(root->left, p, q);
       if (left && left != p && left != q) return left;
       TreeNode *right = lowestCommonAncestor(root->right, p , q);
��������if (left && right) return root;
       return left ? left : right;
    }
};
