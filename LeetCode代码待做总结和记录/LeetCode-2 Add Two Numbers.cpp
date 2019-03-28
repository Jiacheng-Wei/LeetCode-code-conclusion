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
        ListNode *p=&head;//定义头结点方便操作 
        ListNode *p1=l1,*p2=l2;
        int carry=0;//存储进位 
        while (p1!=NULL||p2!=NULL)
        {
            int x=(p1!=NULL)?p1->val:0;
            int y=(p2!=NULL)?p2->val:0;
            int sum=x+y+carry;
            carry=sum/10;
            p->next=new ListNode(sum%10);//创建新的节点 
            p=p->next;
            if (p1!=NULL) p1=p1->next;
            if (p2!=NULL) p2=p2->next;
        }
        if (carry>0) p->next=new ListNode(carry);//目的是实现最后一位的进位 
        return head.next;
    }   
};
