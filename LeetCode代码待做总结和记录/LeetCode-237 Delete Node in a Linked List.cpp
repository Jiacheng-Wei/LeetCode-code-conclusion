//这题就是一个很坑的题，并不是删除当前的节点，而是间接的把下一个节点删了，实现删除当前节点，即把下一个节点的值赋值给当前节点 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};
