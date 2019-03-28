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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);//先声明定义一个头结点 
        ListNode *p=&head;
        while (l1&&l2)//先判断l1,l2是否为空 
        {
            if (l1->val<l2->val)
            {
                p->next=l1;//先连，将头结点先连到较小的节点上 ，下面连l2同理 
                l1=l1->next;//连上后，l1指针后移到下一个节点，下一个l2同理 
            }
            else
            {
                p->next=l2;
                l2=l2->next;
            }
            p=p->next;
        }
        if (l1)
        {
            p->next=l1;//如果有一个队列为空，则直接将另一个队列连在头结点后面即可 
        }
        if(l2)
        {
            p->next=l2;
        }
        return head.next;//返回头结点后面的节点首地址即可 
    }
};
/*
当某个链表为空了，就返回另一个。然后核心还是比较当前两个节点值大小，如果l1的小，那么对于l1的下一个节点和l2调用递归函数，
将返回值赋值给l1.next，然后返回l1；否则就对于l2的下一个节点和l1调用递归函数，将返回值赋值给l2.next，然后返回l2，
参见代码如下：
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
/*下面这种递归的写法去掉了if从句，看起来更加简洁一些，但是思路并没有什么不同：*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *head = l1->val < l2->val ? l1 : l2;
        ListNode *nonhead = l1->val < l2->val ? l2 : l1;
        head->next = mergeTwoLists(head->next, nonhead);
        return head;
    }
};
//三行搞定，虽然代码量少了，但是基本思想是不变的 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || (l2 && l1->val > l2->val)) swap(l1, l2);
        if (l1) l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
};
