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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p=head;
        if (p==NULL||p->next==NULL) return head;
		//��һ�α���ĵط�����������ʱһ��Ҫ�����ж������Ƿ�Ϊ�գ�����漰������ָ����⣬һ��ҲҪ�жϵڶ���ָ���Ƿ�Ϊ�� 
        ListNode *Next=p->next;
        while (p->next!=NULL)
		//�ڶ��α���ĵط����������ж���p->next!=NULL,������Next->next����Ϊ��p=p->nextʱNext�Ѿ�ָ����NULL���Բ��ᳬ�� 
        {
            if (p->val==Next->val)
            {
                p->next=Next->next;
                Next=Next->next;//һ��Ҫ��������� 
            }
            else 
            {
                p=p->next;
                Next=Next->next;
            }
        }
        return head;
    }
};
//�������� 
