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
        for (int i=1;i<=m-1;i++) cur=cur->next;//��һ��ʹ��curָ��֪����Ҫת���Ӵ���ǰһ��ֵ 
        pre=cur;
        last=cur->next;//last�洢��ת�������һ��ֵ 
        for (int i=m;i<=n;i++)
        {
            cur=pre->next;
            pre->next=cur->next;
            cur->next=front;
            front=cur;
        }//front�洢ת�����ĵ�һ��ֵ 
        cur=pre->next;
        pre->next=front;
        last->next=cur;
        return prehead.next;
    }
};
/*
������������⣬���������ľ���һ�㶼��Ҫ��һ��dummy node������ԭ�����ͷ��㣬�����Ļ�����ͷ���䶯�ˣ����ǻ�����ͨ��dummy->next
������������ͷ��㡣������Ҫ����ֻͨ��һ�α�����ɣ�������Ŀ�е�������˵���任����2,3,4�������㣬��ô���ǿ�����ȡ��2����front
ָ��ָ��2��Ȼ��ȡ��3��ʱ�����ǰ�3�ӵ�2��ǰ�棬��frontָ��ǰ�Ƶ�3���������ƣ���4��ֹͣ���������ǵõ�һ��������4->3->2, frontָ
��ָ��4������ԭ������˵�����������λ�ú���Ҫ����Ҫ��ָ���¼�������ֱ���1��5����Ϊ��2,3,4��ȡ��ʱ��ԭ����ͱ����1->5->NULL��Ҫ
������������ʱ����Ҫ���������λ�á�1��λ�úܺ��ң���Ϊ֪��m��ֵ��������preָ���¼1��λ�ã�5��λ�������ܼ�¼����4��㱻ȡ�ߺ�
5��λ����Ҫ���������������ǾͿ��԰ѵ��ú����һС��������뵽ԭ�����С��������ϣ�
*/ 
