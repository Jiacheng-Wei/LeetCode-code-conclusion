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
        ListNode *pre=NULL;//����ΪNULL��Ϊ�˽�ԭʼheadָ�뷭ת��ָ��NULL�� 
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
//�����ǣ���һ��ָ��洢��ǰָ�����һ��ָ�룬����һ��ָ��洢��һ����ǰָ�����һ��ָ�룬Ȼ��ֵ���ɡ��÷�����ʱ�临�Ӷ���O(n)��
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;//����ģ�head�ж��Ǳ�����ֿ��������� 
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};
//�����ķ�����
/*
The recursive version is slightly trickier and the key is to work backwards. Assume that the rest of the 
list had already been reversed, now how do I reverse the front part? Let's assume the list is: n1 �� �� �� nk-1 �� nk �� nk+1 �� �� �� nm �� null
Assume from node nk+1 to nm had been reversed and you are at node nk.
n1 �� �� �� nk-1 �� nk �� nk+1 �� �� �� nm
We want nk+1��s next node to point to nk.
So,
nk.next.next = nk;
Be very careful that n1's next must point to ?. If you forget about this, your linked list has a cycle in it. 
This bug could be caught if you test your code with a linked list of size 2.
*/ 
//���˺ܾ������������ĵݹ�ԭ�� ���������õݹ�һֱ�ݹ鵽���һ��Ԫ�أ�Ȼ�󷵻�head�洢��pָ����ߣ�Ȼ���ڴӺ���ǰִ��ָ�뽻����
//��p��ֵһֱû�иı䣬һֱ�����һ��Ԫ�صĵ�ַ��ֵ�� 
 
