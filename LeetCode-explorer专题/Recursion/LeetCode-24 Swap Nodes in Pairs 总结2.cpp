/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
递归解法的方便之处就是十分的简单，我认为这一题的关键是理解返回的节点的问题，把每两个节点视作一对,
然后将递归函数的返回值设定为每一对的头结点，就是后面那一个节点，这就相当于是在往down-up操作了，
递归到最末端开始交换操作，然后不断回溯做交换操作。 
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
//迭代方法，需要预先设置一个dummy(虚拟)节点，然后进行操作
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
