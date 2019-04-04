/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 ����Ĳ�������ʵ��ԭ��ܼ򵥣�����һ��Ԫ��һ��Ԫ�صĴ�ԭ������ȡ������Ȼ��˳����뵽�������У�
 ʱ�临�Ӷ�ΪO(n2)����һ��Ч�ʲ����Ǻܸߵ��㷨�����ǿռ临�Ӷ�ΪO(1)���Ը�ʱ�临�ӶȻ�ȡ�˵Ϳռ�
 ���Ӷȡ��������£�
 */ 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode(-1),*cur=dummy;//���������������������趨һ����ʼ�ڵ�dummy 
        while(head){
            ListNode* t=head->next;//Ԥ���趨��һ���ڵ㣬�������ѭ�� 
            cur=dummy;
            while(cur->next&&cur->next->val<=head->val){//������ж�һ����cur->next->val ���бȽϣ�Ȼ���ж�һ��ʱcur->next->val<=head->val 
                cur=cur->next;
            }
            head->next=cur->next;//�� 
            cur->next=head;//�� 
            head=t;
        }
        return dummy->next;
    }
};
