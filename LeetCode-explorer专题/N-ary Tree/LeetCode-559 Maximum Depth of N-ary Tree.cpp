/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/*
���ĵݹ�ⷨ�ĵ�һ��top-down���ϵ��µĽⷨ������Ľ��Ϳ��Կ�LeetCode������ܽ᣺ 
https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/534/ 
����������������ģ�壺
int answer;		       // don't forget to initialize answer before call maximum_depth
void maximum_depth(TreeNode* root, int depth) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        answer = max(answer, depth);
    }
    maximum_depth(root->left, depth + 1);
    maximum_depth(root->right, depth + 1);
} 
*/ 
class Solution {
public:
    int maxDepth(Node* root) {
        int res=0;
        recursive(res,1,root);
        return res;
    }
    
    void recursive(int& answer,int index,Node* root)
    {
        if(!root) return;
        if(root->children.empty()) answer=max(answer,index);
        for(auto n:root->children)
        {
            recursive(answer,index+1,n);
        }
    }
};
/*
��һ�ֽⷨ��bottom-up�Ľⷨ����ϸ������Ȼ���������ַ������������Ǵ��෽���Ľ���ģ�壺
int maximum_depth(TreeNode* root) {
	if (!root) {
		return 0;                                 // return 0 for null node
	}
	int left_depth = maximum_depth(root->left);	
	int right_depth = maximum_depth(root->right);
	return max(left_depth, right_depth) + 1;	  // return depth of the subtree rooted at root
} 
*/ 
class Solution {
public:
    int maxDepth(Node* root) {
        int res=recursive(root);
        return res;
    }
    
    int recursive(Node* root)
    {
        if(!root) return 0;
        int mx=0;
        for(auto n:root->children)
        {
            mx=max(mx,recursive(n));
        }
        return mx+1;//+1��һ��һ��Ҫ���ڷ��ص��ţ��������ÿһ�α����ӽڵ㶼���һ�����ս�������ʵ�ʽ�� 
    }
};
