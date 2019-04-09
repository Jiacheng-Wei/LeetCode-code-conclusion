/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //�б�Ҫ��¼һ�������������ĵķ���������һ���ܴ����˼·����Ϊ��û�п��ǵ�������x�����������нڵ��ֵ������������ͻ������ѭ�� 
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
�����Ҫ�����ǻ�������������С�ڸ���ֵ�Ľڵ㶼�Ƶ�ǰ�棬���ڸ�ֵ�Ľڵ�˳�򲻱䣬�൱��һ���ֲ���������⡣
��ô�����뵽��һ�ֽⷨ�������ҵ���һ�����ڻ���ڸ���ֵ�Ľڵ㣬����Ŀ�и���������˵�������ҵ�4��Ȼ������С��3��ֵ��
ÿ�ҵ�һ���ͽ���ȡ������4֮ǰ���ɣ��������£�
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
���⻹��һ�ֽⷨ�����ǽ�����С�ڸ���ֵ�Ľڵ�ȡ�����һ���µ�������ʱԭ������ʣ��Ľڵ��ֵ�����ڻ����
����ֵ��ֻҪ��ԭ����ֱ�ӽ���������󼴿ɣ��������£�
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
