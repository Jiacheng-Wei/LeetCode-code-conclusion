/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//迭代方法：这个方法值设了一个指针，比我原来设三个指针好多了，而且也避免了指针在变换过程中指飞的问题，复习时画图分析，链表的基本操作 
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
//递归方法：相当于是将head指针递归到最后，从后往前进行相邻节点的排列顺序的交换 
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
 

