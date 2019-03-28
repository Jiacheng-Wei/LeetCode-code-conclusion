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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head=ListNode(0);
        ListNode *p=&head;//����ͷ��㷽����� 
        ListNode *p1=l1,*p2=l2;
        int carry=0;//�洢��λ 
        while (p1!=NULL||p2!=NULL)
        {
            int x=(p1!=NULL)?p1->val:0;
            int y=(p2!=NULL)?p2->val:0;
            int sum=x+y+carry;
            carry=sum/10;
            p->next=new ListNode(sum%10);//�����µĽڵ� 
            p=p->next;
            if (p1!=NULL) p1=p1->next;
            if (p2!=NULL) p2=p2->next;
        }
        if (carry>0) p->next=new ListNode(carry);//Ŀ����ʵ�����һλ�Ľ�λ 
        return head.next;
    }   
};
