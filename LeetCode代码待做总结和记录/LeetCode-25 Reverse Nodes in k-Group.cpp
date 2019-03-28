/*
这道题让我们以每k个为一组来翻转链表，实际上是把原链表分成若干小段，然后分别对其进行翻转，那么肯定总共需要两个函数，
一个是用来分段的，一个是用来翻转的，我们就以题目中给的例子来看，对于给定链表1->2->3->4->5，一般在处理链表问题时，
我们大多时候都会在开头再加一个dummy node，因为翻转链表时头结点可能会变化，为了记录当前最新的头结点的位置而引入的dummy node，
那么我们加入dummy node后的链表变为-1->1->2->3->4->5，如果k为3的话，我们的目标是将1,2,3翻转一下，那么我们需要一些指针，pre和next
分别指向要翻转的链表的前后的位置，然后翻转后pre的位置更新到如下新的位置：
-1->1->2->3->4->5
 |           |
pre         next

-1->3->2->1->4->5
          |  |
         pre next
*/
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || k == 1) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy, *cur = head;
        dummy->next = head;
        int i = 0;
        while (cur) {
            ++i;
            if (i % k == 0) {
                pre = reverseOneGroup(pre, cur->next);
                cur = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
    ListNode *reverseOneGroup(ListNode *pre, ListNode *next) {
        ListNode *last = pre->next;
        ListNode *cur = last->next;
        while(cur != next) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        return last;
    }
};
/*
我们也可以在一个函数中完成，我们首先遍历整个链表，统计出链表的长度，然后如果长度大于等于k，我们开始交换节点，
当k=2时，每段我们只需要交换一次，当k=3时，每段需要交换2此，所以i从1开始循环，注意交换一段后更新pre指针，然后num自减k，
直到num<k时循环结束，参见代码如下：
*/ 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = pre;
        dummy->next = head;
        int num = 0;
        while (cur = cur->next) ++num;
        while (num >= k) {
            cur = pre->next;
            for (int i = 1; i < k; ++i) {
                ListNode *t = cur->next;
                cur->next = t->next;
                t->next = pre->next;
                pre->next = t;
            }
            pre = cur;
            num -= k;
        }
        return dummy->next;
    }
};
/*
我们也可以使用递归来做，我们用head记录每段的开始位置，cur记录结束位置的下一个节点，然后我们调用reverse函数来将这段翻转，
然后得到一个new_head，原来的head就变成了末尾，这时候后面接上递归调用下一段得到的新节点，返回new_head即可，参见代码如下：
方法理解，因为题目有回溯的过程，所以最终的回溯结果是整个队列的头结点 
*/ 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur = head;
        for (int i = 0; i < k; ++i) {
            if (!cur) return head;
            cur = cur->next;
        }
        ListNode *new_head = reverse(head, cur);
        head->next = reverseKGroup(cur, k);
        return new_head;
    }
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode *pre = tail;
        while (head != tail) {
            ListNode *t = head->next;
            head->next = pre;
            pre = head;
            head = t;
        }
        return pre;
    }
};
