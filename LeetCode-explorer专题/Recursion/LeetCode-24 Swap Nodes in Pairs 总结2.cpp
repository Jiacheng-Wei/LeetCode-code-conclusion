/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
�ݹ�ⷨ�ķ���֮������ʮ�ֵļ򵥣�����Ϊ��һ��Ĺؼ�����ⷵ�صĽڵ�����⣬��ÿ�����ڵ�����һ��,
Ȼ�󽫵ݹ麯���ķ���ֵ�趨Ϊÿһ�Ե�ͷ��㣬���Ǻ�����һ���ڵ㣬����൱��������down-up�����ˣ�
�ݹ鵽��ĩ�˿�ʼ����������Ȼ�󲻶ϻ��������������� 
*/ 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* t=head->next;
        head->next=swapPairs(head->next->next);
        t->next=head;
        return t;
    }
};
//������������ҪԤ������һ��dummy(����)�ڵ㣬Ȼ����в���
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        while (pre->next && pre->next->next) {
            ListNode *t = pre->next->next;
            pre->next->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pre = t->next;
        }
        return dummy->next;
    }
}; 
