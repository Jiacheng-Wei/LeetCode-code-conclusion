//�������һ���ܿӵ��⣬������ɾ����ǰ�Ľڵ㣬���Ǽ�ӵİ���һ���ڵ�ɾ�ˣ�ʵ��ɾ����ǰ�ڵ㣬������һ���ڵ��ֵ��ֵ����ǰ�ڵ� 
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
