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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode prehead(0);
        prehead.next=head;
        ListNode *cur=&prehead;
        ListNode *front,*last,*pre;
        for (int i=1;i<=m-1;i++) cur=cur->next;//这一步使得cur指针知道了要转化子串的前一个值 
        pre=cur;
        last=cur->next;//last存储翻转完后的最后一个值 
        for (int i=m;i<=n;i++)
        {
            cur=pre->next;
            pre->next=cur->next;
            cur->next=front;
            front=cur;
        }//front存储转换完后的第一个值 
        cur=pre->next;
        pre->next=front;
        last->next=cur;
        return prehead.next;
    }
};
/*
对于链表的问题，根据以往的经验一般都是要建一个dummy node，连上原链表的头结点，这样的话就算头结点变动了，我们还可以通过dummy->next
来获得新链表的头结点。这道题的要求是只通过一次遍历完成，就拿题目中的例子来说，变换的是2,3,4这三个点，那么我们可以先取出2，用front
指针指向2，然后当取出3的时候，我们把3加到2的前面，把front指针前移到3，依次类推，到4后停止，这样我们得到一个新链表4->3->2, front指
针指向4。对于原链表连说，有两个点的位置很重要，需要用指针记录下来，分别是1和5，因为当2,3,4被取走时，原链表就变成了1->5->NULL，要
把新链表插入的时候需要这两个点的位置。1的位置很好找，因为知道m的值，我们用pre指针记录1的位置，5的位置最后才能记录，当4结点被取走后，
5的位置需要记下来，这样我们就可以把倒置后的那一小段链表加入到原链表中。代码如上：
*/ 
