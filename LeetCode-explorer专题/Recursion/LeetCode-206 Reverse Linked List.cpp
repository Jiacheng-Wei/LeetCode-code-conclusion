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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=NULL;//声明为NULL是为了将原始head指针翻转后指向NULL。 
        ListNode *cur=head;
        while (cur!=NULL)
        {
            ListNode *nextTemp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nextTemp;
        }
        return pre;
    }
};
//方法是，用一个指针存储当前指针的上一个指针，用另一个指针存储下一个当前指针的上一个指针，然后赋值即可。该方法的时间复杂度是O(n)。
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;//这里的！head判断是避免出现空链表的情况 
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};
//迭代的方法。
/*
The recursive version is slightly trickier and the key is to work backwards. Assume that the rest of the 
list had already been reversed, now how do I reverse the front part? Let's assume the list is: n1 → … → nk-1 → nk → nk+1 → … → nm → null
Assume from node nk+1 to nm had been reversed and you are at node nk.
n1 → … → nk-1 → nk → nk+1 ← … ← nm
We want nk+1’s next node to point to nk.
So,
nk.next.next = nk;
Be very careful that n1's next must point to ?. If you forget about this, your linked list has a cycle in it. 
This bug could be caught if you test your code with a linked list of size 2.
*/ 
//想了很久明白了这道题的递归原理， 就是现利用递归一直递归到最后一个元素，然后返回head存储在p指针里边，然后在从后往前执行指针交换，
//而p的值一直没有改变，一直是最后一个元素的地址的值。 
 
