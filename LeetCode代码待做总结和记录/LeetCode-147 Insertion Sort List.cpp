/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 链表的插入排序实现原理很简单，就是一个元素一个元素的从原链表中取出来，然后按顺序插入到新链表中，
 时间复杂度为O(n2)，是一种效率并不是很高的算法，但是空间复杂度为O(1)，以高时间复杂度换取了低空间
 复杂度。代码如下：
 */ 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode(-1),*cur=dummy;//对于链表本身操作都最后先设定一个起始节点dummy 
        while(head){
            ListNode* t=head->next;//预先设定下一个节点，方便后续循环 
            cur=dummy;
            while(cur->next&&cur->next->val<=head->val){//这里的判断一定是cur->next->val 进行比较，然后判断一定时cur->next->val<=head->val 
                cur=cur->next;
            }
            head->next=cur->next;//连 
            cur->next=head;//断 
            head=t;
        }
        return dummy->next;
    }
};
