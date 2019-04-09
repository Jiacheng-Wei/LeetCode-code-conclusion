/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //有必要记录一下下面这个错误的的方法，这是一个很错误的思路，因为并没有考虑到所给的x大于链表所有节点的值的情况，这样就会出现死循环 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *pre=dummy,*cur=head,*pre1=dummy;
        if(cur->val<x){
            cur=cur->next;
            pre=pre->next;
            pre1=pre1->next;
        }
        while(cur!=NULL){
            ListNode* t=cur->next;
            if(cur->val<x){
                pre1->next=t;
                cur->next=pre->next;
                pre->next=cur;
                pre=pre->next;
            }
            else{
                pre1=pre1->next;
            }
            cur=t;
        }
        return dummy->next;
    }
};
/*
这道题要求我们划分链表，把所有小于给定值的节点都移到前面，大于该值的节点顺序不变，相当于一个局部排序的问题。
那么可以想到的一种解法是首先找到第一个大于或等于给定值的节点，用题目中给的例子来说就是先找到4，然后再找小于3的值，
每找到一个就将其取出置于4之前即可，代码如下：
*/ 
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;;
        while (pre->next && pre->next->val < x) pre = pre->next;
        cur = pre;
        while (cur->next) {
            if (cur->next->val < x) {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
                pre = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
/*
此题还有一种解法，就是将所有小于给定值的节点取出组成一个新的链表，此时原链表中剩余的节点的值都大于或等于
给定值，只要将原链表直接接在新链表后即可，代码如下：
*/ 
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *newDummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy, *p = newDummy;
        while (cur->next) {
            if (cur->next->val < x) {
                p->next = cur->next;
                p = p->next;
                cur->next = cur->next->next;
                p->next = NULL;
            } else {
                cur = cur->next;
            }
        }
        p->next = dummy->next;
        return newDummy->next;
    }
};
