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
		//第一次报错的地方，做链表题时一定要首先判断链表是否为空，如果涉及到两个指针的题，一定也要判断第二个指针是否为空 
        ListNode *Next=p->next;
        while (p->next!=NULL)
		//第二次报错的地方，结束的判断是p->next!=NULL,而不是Next->next，因为当p=p->next时Next已经指向了NULL所以不会超界 
        {
            if (p->val==Next->val)
            {
                p->next=Next->next;
                Next=Next->next;//一定要是先连后断 
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
//链表问题 
