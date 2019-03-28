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
        ListNode head(0);//����������һ��ͷ��� 
        ListNode *p=&head;
        while (l1&&l2)//���ж�l1,l2�Ƿ�Ϊ�� 
        {
            if (l1->val<l2->val)
            {
                p->next=l1;//��������ͷ�����������С�Ľڵ��� ��������l2ͬ�� 
                l1=l1->next;//���Ϻ�l1ָ����Ƶ���һ���ڵ㣬��һ��l2ͬ�� 
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
            p->next=l1;//�����һ������Ϊ�գ���ֱ�ӽ���һ����������ͷ�����漴�� 
        }
        if(l2)
        {
            p->next=l2;
        }
        return head.next;//����ͷ������Ľڵ��׵�ַ���� 
    }
};
/*
��ĳ������Ϊ���ˣ��ͷ�����һ����Ȼ����Ļ��ǱȽϵ�ǰ�����ڵ�ֵ��С�����l1��С����ô����l1����һ���ڵ��l2���õݹ麯����
������ֵ��ֵ��l1.next��Ȼ�󷵻�l1������Ͷ���l2����һ���ڵ��l1���õݹ麯����������ֵ��ֵ��l2.next��Ȼ�󷵻�l2��
�μ��������£�
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
/*�������ֵݹ��д��ȥ����if�Ӿ䣬���������Ӽ��һЩ������˼·��û��ʲô��ͬ��*/
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
//���и㶨����Ȼ���������ˣ����ǻ���˼���ǲ���� 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || (l2 && l1->val > l2->val)) swap(l1, l2);
        if (l1) l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
};
