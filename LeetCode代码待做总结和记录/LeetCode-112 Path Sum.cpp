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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        sum-=root->val;
        if(!root->right&&!root->left) return (sum==0);
        return hasPathSum(root->right,sum)||hasPathSum(root->left,sum);   
    }
};
//递归的方式，一直向下递归，递归到底过后判断sum是否为零，如果为零则true，否则为false，还有这里的递归是否并没有回溯，所以要多总结类似的递归题，找异同
//时间复杂度是O(N)，空间复杂度是O(log(N))
/*
We could also convert the above recursion into iteration, with the help of stack. DFS would be better than BFS here since it works faster 
except the worst case. In the worst case the path root->leaf with the given sum is the last considered one and in this case DFS results in 
the same productivity as BFS.
The idea is to visit each node with the DFS strategy, while updating the remaining sum to cumulate at each visit.
So we start from a stack which contains the root node and the corresponding remaining sum which is sum - root.val. Then we proceed to the 
iterations: pop the current node out of the stack and return True if the remaining sum is 0 and we're on the leaf node. If the remaining sum 
is not zero or we're not on the leaf yet then we push the child nodes and corresponding remaining sums into stack.
*/ 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        stack<TreeNode*> st_node;
        stack<int> st_sum;
        st_node.push(root);
        st_sum.push(sum-root->val);
        while(!st_node.empty())
        {
            TreeNode* node=st_node.top();
            st_node.pop();
            int cur_sum=st_sum.top();
            st_sum.pop();
            if(!node->left&&!node->right&&cur_sum==0) return true;
            if(node->left)
            {
                st_node.push(node->left);
                st_sum.push(cur_sum-node->left->val);
            }
            if(node->right)
            {
                st_node.push(node->right);
                st_sum.push(cur_sum-node->right->val);
            }
        }
        return false;
    }
};
