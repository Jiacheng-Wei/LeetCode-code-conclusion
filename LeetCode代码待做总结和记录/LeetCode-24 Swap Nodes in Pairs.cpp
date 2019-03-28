/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//�����������������ֵ����һ��ָ�룬����ԭ��������ָ��ö��ˣ�����Ҳ������ָ���ڱ任������ָ�ɵ����⣬��ϰʱ��ͼ����������Ļ������� 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode node=ListNode(0);
        node.next=head;
        ListNode *pre=&node;
        while(pre->next!=NULL&&pre->next->next!=NULL)
        {
            ListNode *t=pre->next->next;
            pre->next->next=t->next;
            t->next=pre->next;
            pre->next=t;
            pre=t->next;
        }
        return node.next;
    }
};
//�ݹ鷽�����൱���ǽ�headָ��ݹ鵽��󣬴Ӻ���ǰ�������ڽڵ������˳��Ľ��� 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *t=head->next;
        head->next=swapPairs(head->next->next);
        t->next=head;
        return t;
    }
}; 
 

