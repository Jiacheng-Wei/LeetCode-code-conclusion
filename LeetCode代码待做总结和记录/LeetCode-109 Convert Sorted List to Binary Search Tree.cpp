//����һ��ת��������ķ����������ڴ�ᳬ��
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *Last=head;
        vector<int> nums;
        int size=0;
        while (Last!=NULL)
        {
            size++;
            nums.push_back(Last->val);
            Last=Last->next;
        }
        return buildTree(nums,0,size-1);
    }
    TreeNode* buildTree(vector<int> nums,int left,int right)
    {
        if(left>right) return NULL;
        int mid=left+(right-left)/2;
        TreeNode *cur=new TreeNode(nums[mid]);
        cur->left=buildTree(nums,left,mid-1);
        cur->right=buildTree(nums,mid+1,right);
        return cur;
    }
}; 
/*
�������Ҫ�����������תΪ��������������֮ǰ�ǵ�Convert Sorted Array to Binary Search Tree ����������תΪ����������˼·��ȫһ����
ֻ�����ǲ��������������������һ�������飬һ�����������鷽��ͷ����ڿ���ͨ��indexֱ�ӷ�������һ��Ԫ�أ��������С����ڶ���
���ҷ�ÿ����Ҫ�ҵ��е㣬������Ĳ����м�����ͨ������ָ�����������ɲμ�֮ǰ����ƪ����Reorder List �����������Linked List Cycle II 
�������еĻ�֮���йؿ���ָ���Ӧ�á��ҵ��е��Ҫ���е��ֵ����һ�����ĸ��ڵ㣬Ȼ����Ҫ��ԭ����Ͽ�����Ϊǰ���������������ܰ���ԭ
�нڵ㣬Ȼ���ٷֱ������������ݹ����ԭ�������ֱ����������ӽڵ㼴�ɡ��������£�
*/ 
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *last = slow;
        while (fast->next && fast->next->next) {
            last = slow;//ע�������last��֤���ڷָ�����ʱ��lastָ����slowָ���ǰһ��ֵ��Ҳ���������������һ��ֵ������last->next=NULL�����ڷ��������� 
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        last->next = NULL;
        TreeNode *cur = new TreeNode(slow->val);
        if (head != slow) cur->left = sortedListToBST(head);
        cur->right = sortedListToBST(fast);
        return cur;
    }
};
